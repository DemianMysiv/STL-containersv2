#include <iostream>
#include <array>
#include "Employee.h"
#include <vector>
#include <deque>


using namespace std;

template<typename T>

void function1(std::vector<T> vec1, std::vector<T>& even, std::vector<T>& odd) {




    for (auto vectorIterator = vec1.begin(); vectorIterator != vec1.end(); ++vectorIterator) {
        if (*vectorIterator % 2 == 0) {
            even.push_back(*vectorIterator);
        } else {
            odd.push_back(*vectorIterator);
        }
    }
};


template<typename T, size_t N>
void sortContainer(std::array<T, N>& arr) {

    if (N <= 1) return;

    for (auto it = arr.begin(); it != arr.end(); ++it) {

        for (auto jt = arr.begin(); jt != arr.end() - 1; ++jt) {
            auto jttonext = jt + 1;
            if (*jttonext < *jt) {
                std::swap(*jt, *jttonext);
            }
        }
    }
}



  
template<typename T, size_t N>
array<T, N * 2> createSortedMergedArray(const array<T, N>& arr1, const array<T, N>& arr2) {
    array<T, N * 2> result; 
    
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    auto it_res = result.begin();

while (it1 != arr1.end() && it2 != arr2.end()) {

    *it_res = (*it1 < *it2) ? *it1 : *it2;

    if (*it1 < *it2)
        ++it1;
    else
        ++it2;
    
    ++it_res;
}


    while (it1 != arr1.end()) {
        *it_res = *it1;
        it1++;
        it_res++;
    }

    while (it2 != arr2.end()) {
        *it_res = *it2;
        it2++;
        it_res++;
    }

    return result;
}

// 3. Точка входу
int main() {



    array<Employee, 5> arr1 = {
        Employee("Demyan", 1000),
        Employee("Yaroslav", 2000),
        Employee("Oleksandr", 4000),
        Employee("Oleh", 1050),
        Employee("Ihor", 3000)
    };

    array<Employee, 5> arr2 = {
        Employee("Andriy", 2500),
        Employee("Viktor", 4500),
        Employee("Taras", 1500),
        Employee("Bohdan", 3500),
        Employee("Roman", 1250)
    };

    // Сортуємо їх нашими ітераторами
    sortContainer(arr1);
    cout << "--- Sorted arr1 ---" << endl;
    for (auto it = arr1.begin(); it != arr1.end(); ++it) {
        cout << "Name: " << it->getName() << "\t | Salary: " << it->getSalary() << endl;
    }  

    sortContainer(arr2);
    cout << "--- Sorted arr2 ---" << endl;
    for (auto it = arr2.begin(); it != arr2.end(); ++it) {
        cout << "Name: " << it->getName() << "\t | Salary: " << it->getSalary() << endl;
    }
    

    // Об'єднуємо два відсортовані масиви в один (на 10 елементів)
    auto mergedArray = createSortedMergedArray(arr1, arr2);

    // Виводимо результат
    cout << "--- Sorted and merged array ---" << endl;
    for (auto it = mergedArray.begin(); it != mergedArray.end(); ++it) {
        cout << "Name: " << it->getName() << "\t | Salary: " << it->getSalary() << endl;
    }




/*     std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> even;
    std::vector<int> odd;



    function1(vec1, even, odd);


    cout<< "Even numbers: ";
    for (auto it = even.begin(); it != even.end(); ++it) {
        cout << *it << " ";
    }

    cout<< "\nOdd numbers: ";
    for(auto it = odd.begin(); it != odd.end(); ++it) {
        cout << *it << " ";
    }

 


    std::vector<Employee> employees = {
        Employee("Demyan", 1000),
        Employee("Yaroslav", 2045),
        Employee("Oleksandr", 4000),
        Employee("Oleh", 5000),
        Employee("Ihor", 3333)
    };

    std::vector<Employee> even1;
    std::vector<Employee> odd1;

    function1(employees, even1, odd1);

    cout<< "\nEven salary employees: "<< endl;
    for (auto it = even1.begin(); it != even1.end(); ++it) {
        cout << it->getName() << " "<< it->getSalary() << endl;
    }

    cout<< "\nOdd salary employees: "<< endl;
    for(auto it = odd1.begin(); it != odd1.end(); ++it) {
        cout << it->getName() << " "<< it->getSalary() << endl;
    }   
 */

    return 0;
};