#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "func.h"
// підключення бібліотек

using namespace std;

int main(int argc, char* argv[]){
    // перевірка на режим "FileStream"
    if (isMode("FileStream", argc, argv)) {
    cout << "Running in FileStream mode" << endl;
    // вивід повідомлення про режим роботи
    char ch, check;
    string filename;
    do {
        cout << "Enter filename: ";
        cin >> filename;
        // введення та сканування файлу
        string fullname = filename + ".txt";
        string new_fullname = filename + "_new" + ".txt";
        // створення повних назв з розширенням "txt"
         if (!ifstream(fullname)) {
            // перевірка на не існування файлу з заданою назвою
                file_create(fullname);
                // функція створення файлу
                cout << "File " << filename << " created." << endl;
                // виведення повідомлення про створення файлу
                do{
                file_append(fullname);
                // функція допису тексту до файла
                cout << "\nYour file " << fullname << ":\n";
                file_output(fullname);
                // функція виведенян файла
                cout << "\nPress y if you want to work with this file or press any other key to append it: ";
                cin >> check;
                // запит чи користувач хоче працювати з цим файлом
                }while (check != 'y');
                file_sort(fullname, new_fullname);
                // функція сортування файла та створення нового з результатом
                cout << "\nNew file " << new_fullname << ": \n\n";
                file_output(new_fullname);
                // виведення нового файла
         }
         else{
            cout << "\nFile with name " << filename << " already exists" << endl;
            cout << "Output of this file: \n";
            // виведення повідомлення про існування файла з такою назвою
            do{
                file_output(fullname);
                // функція виведення вмісту файла
                cout << "\nPress y if you want to work with this file or press any other key to append it: ";
                cin >> check;
                // запит чи користувач хоче працювати з цим файлом
                if(check != 'y'){file_append(fullname);}
                // функцію додання до файлу, якщо користувач не погодився
                }while (check != 'y');
            file_sort(fullname, new_fullname);
            // функція сортування файла та створення нового з результатом
            cout << "\nNew file " << new_fullname << ": \n\n";
            file_output(new_fullname);
            // виведення нового файла
         }
        cout << "Press (y) to try again: ";
        cin >> ch;
        // перевірка чи користувач хоче попробувати ще раз
    }while(ch == 'y');
    }
    else if (isMode("FilePointer", argc, argv)) {
        // перевірка на режим "FilePointer"
    cout << "Running in FilePointer mode" << endl;
    char ch, check;
    char filename[50];
    do {
        cout << "Enter filename: ";
        cin >> filename;
        // Зчитування імені файлу зі стандартного вводу
        char fullname[50];
        // Створення масиву символів, який буде містити повне ім'я вхідного файлу, включаючи розширення
        strcpy(fullname, filename);
        // Копіювання імені файлу у масив символів fullname
        strcat(fullname, ".txt");
        // Додавання розширення .txt до повного імені файлу
        char new_fullname[50];
        // Створення масиву символів, який буде містити повне ім'я вихідного файлу, включаючи розширення
        strcpy(new_fullname, filename);
        // Копіювання імені файлу у масив символів new_fullname
        strcat(new_fullname, "_new");
        // Додавання рядка "_new" до повного імені файлу
        strcat(new_fullname, ".txt");
        // Додавання розширення .txt до повного імені файлу
        if (!ifstream(fullname)) {
            // перевірка на не існування файла
            file_create(&fullname[0]);
            // функція створення файла
            cout << "File " << fullname << " created." << endl;
            do {
                file_append(&fullname[0]);
                // функція додання тексту до файла
                cout << "\nYour file " << fullname << ":\n";
                file_output(&fullname[0]);
                // функція виведення з файлу
                cout << "\nPress y if you want to work with this file or press any other key to append it: ";
                cin >> check;
                // запит чи користувач хоче працювати з цим файлом
            } while (check != 'y');
            file_sort(&fullname[0], &new_fullname[0]);
            // функція сортування файла та створення нового з результатом
            cout << "\nNew file " << new_fullname << ": \n\n";
            file_output(&new_fullname[0]);
            // виведення нового файла
        }
        else {
            cout << "\nFile with name " << fullname << " already exists" << endl;
            cout << "Output of this file: \n";
            // виведення повідомлення про існування файла з такою назвою
            do {
                file_output(&fullname[0]);
                // функція виведення даних з існуючого файлу
                cout << "\nPress y if you want to work with this file or press any other key to append it: ";
                cin >> check;
                // запит чи користувач хоче працювати з цим файлом
                if(check != 'y'){file_append(&fullname[0]);}
                // функцію додання до файлу, якщо користувач не погодився
            } while (check != 'y');
            file_sort(&fullname[0], &new_fullname[0]);
            // функція сортування файла та створення нового з результатом
            cout << "\nNew file " << new_fullname << ": \n\n";
            file_output(&new_fullname[0]);
            // виведення нового файла
        }
        cout << "Press (y) to try again: ";
        cin >> ch;
        // перевірка чи користувач хоче попробувати ще раз
    } while (ch == 'y');
    }
    else{
        cout << "Incorrect mode specified" << endl;
        // виведення помилки, не валідного режиму
    }
}

