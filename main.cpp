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

template<typename T>

std::string functionfordeque(std::deque<T> deq) {
    std::string result;
   
    auto deqbegin = deq.begin();
    auto deqEnd = deq.end();
    deqEnd--; 

    result = "Palindrome";
    for(int n = 0; n < deq.size()/2; n++) {
    if( *(deqbegin) == *(deqEnd) ) {
        deqbegin++;
        deqEnd--; 
        
    } else {
        result = "Not a palindrome";
        break;
    }
    }

return result;
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

    array<int, 5> arr3 = {5, 2, 9, 1, 5};
    array<int, 5> arr4 = {3, 4, 1, 2, 6};
    
    sortContainer(arr3);
    cout << "--- Sorted arr3 ---" << endl;
    for (auto it = arr3.begin(); it != arr3.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n--- Sorted arr4 ---" << endl;
    for (auto it = arr4.begin(); it != arr4.end(); ++it) {
        cout << *it << " ";
    }      

    auto mergedArray2 = createSortedMergedArray(arr3, arr4);
    cout << "\n--- Sorted and merged array of integers ---" << endl;
    for (auto it = mergedArray2.begin(); it != mergedArray2.end(); ++it) {
        cout << *it << " ";
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


std::deque<Employee> employees = {
    Employee("Demyan", 1000),
    Employee("Yaroslav", 2045),
    Employee("Oleksandr", 4000),
    Employee("Oleh", 5000),
    Employee("Ihor", 3333),
    Employee("Oleh", 5000),
    Employee("Oleksandr", 4000),
    Employee("Yaroslav", 2045),
    Employee("Demyan", 1000)
};

std::deque<Employee> employees2 = {
    Employee("Demyan", 1000),
    Employee("Yaroslav", 2045),
    Employee("Oleksandr", 4000),
    Employee("Oleh", 5000)
};

std::deque<int> deq1 = {1, 2, 3, 4, 5, 4, 3, 2, 1};
std::deque<int> deq2 = {1, 2, 3, 4, 5};

std::string result = functionfordeque(employees);
cout << "The deque employees is: " << result << endl;

std::string result2 = functionfordeque(employees2);
cout << "The deque employees2 is: " << result2 << endl;

std::string result3 = functionfordeque(deq1);
cout << "The deque deq1 is: " << result3 << endl; 

std::string result4 = functionfordeque(deq2);
cout << "The deque deq2 is: " << result4 << endl;


    return 0;

};