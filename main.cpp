#include <iostream>
#include <array>
#include "Employee.h"

using namespace std;

// 1. Шаблонна функція для сортування (тільки std::array, без next/prev)
template<typename T, size_t N>
void sortContainer(std::array<T, N>& arr) {
    if (N <= 1) return;
    
    // Зовнішній цикл (лічильник проходів)
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        
        // Внутрішній цикл зупиняється ЗА ОДИН елемент до кінця (arr.end() - 1)
        for (auto jt = arr.begin(); jt != arr.end() - 1; ++jt) {
            
            auto next_jt = jt + 1; // Використовуємо звичайне додавання ітераторів
            
            // Якщо поточний елемент більший за наступний - міняємо місцями
            if (*next_jt < *jt) { 
                swap(*jt, *next_jt);
            }
        }
    }
}




  
// 2. ОСНОВН  ЗАВДАННЯ: Шаблонна функція для об'єднання двох відсортованих масивів
template<typename T, size_t N>
array<T, N * 2> createSortedMergedArray(const array<T, N>& arr1, const array<T, N>& arr2) {
    array<T, N * 2> result; 
    
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    auto it_res = result.begin();

    // Порівнюємо елементи і записуємо менший у результат
    while (it1 != arr1.end() && it2 != arr2.end()) {
        if (*it1 < *it2) {
            *it_res = *it1;
            it1++;
        } else {
            *it_res = *it2;
            it2++;
        }
        it_res++;
    }

    // Дописуємо залишки першого масиву (якщо є)
    while (it1 != arr1.end()) {
        *it_res = *it1;
        it1++;
        it_res++;
    }

    // Дописуємо залишки другого масиву (якщо є)
    while (it2 != arr2.end()) {
        *it_res = *it2;
        it2++;
        it_res++;
    }

    return result;
}

// 3. Точка входу
int main() {
    // Ініціалізуємо початкові невідсортовані масиви
    array<Employee, 5> arr1 = {
        Employee("Demyan", 1000),
        Employee("Yaroslav", 2000),
        Employee("Oleksandr", 4000),
        Employee("Oleh", 5000),
        Employee("Ihor", 3000)
    };

    array<Employee, 5> arr2 = {
        Employee("Andriy", 2500),
        Employee("Viktor", 4500),
        Employee("Taras", 1500),
        Employee("Bohdan", 3500),
        Employee("Roman", 5500)
    };

    // Сортуємо їх нашими ітераторами
    sortContainer(arr1);
    sortContainer(arr2);

    // Об'єднуємо два відсортовані масиви в один (на 10 елементів)
    auto mergedArray = createSortedMergedArray(arr1, arr2);

    // Виводимо результат
    cout << "--- Відсортований та об'єднаний масив працівників ---" << endl;
    for (auto it = mergedArray.begin(); it != mergedArray.end(); ++it) {
        cout << "Name: " << it->getName() << "\t | Salary: " << it->getSalary() << endl;
    }

    return 0;
}