#include <iostream>
#include <list>

int main() {
    std::list<int> test;
//Добавление элементов в конец списка
    test.push_back(10);
    test.push_back(20);

//Добавление элементов в начало списка
    test.push_front(30);
    test.push_front(40);
    
    std::cout << "Список после добавления элементов: ";
    for(auto it = test.begin(); it != test.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

//Удаление элемента из конца списка
    test.pop_back();

//Удаление элемента из начала списка 
    test.pop_front();

    std::cout << "Список после удаления элементов: ";
    for(auto it = test.begin(); it != test.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

//Добавление нуля в середину
    auto iter1 = test.begin();
    advance(iter1, 1);
    test.insert(iter1, 0);

//Удаление последнего элемента
    auto iter2 = test.begin();
    advance(iter2, 2);
    test.erase(iter2);

    std::cout << "Список после удаления элементов: ";
    for(auto it = test.begin(); it != test.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0; 
}
