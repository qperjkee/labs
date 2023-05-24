#include <iostream>
#include <string>
#include "class.h"

int main() {
    int choice, ch;
    char dec;
    std::cout << "Виберіть тип даних для дерева:\n";
    std::cout << "1. Цілі числа (int)\n";
    std::cout << "2. Дійсні числа (float)\n";
    std::cout << "3. Символи (char)\n";
    std::cout << "4. Рядки (string)\n";
    std::cout << "Ваш вибір: ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Некоректний вибір. Завершення програми.\n";
    }
    
    if (choice == 1) {
        BinaryTree<int> tree;
        tree.processBinaryTree();
    }
    else if (choice == 2) {
        BinaryTree<float> tree;
        tree.processBinaryTree();
    }
    else if (choice == 3) {
        BinaryTree<char> tree;
        tree.processBinaryTree();
    }
    else if (choice == 4) {
        BinaryTree<std::string> tree;
        tree.processBinaryTree();
    }
    return 0;
}