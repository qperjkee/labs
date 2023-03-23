#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include "func.h"
// підключення бібліотек

using namespace std;

int main(){
    char decision, ch, check;
    string filename;
    do{
        cout << "Enter file name: ";
        cin >> filename;
        // введення та сканування файлу
        string fullname = filename + ".bin";
        string new_fullname = filename + "_new" + ".bin";
        // створення повних назв з розширенням "bin"

        if (!ifstream(fullname, ios::binary)) {
            // перевірка на не існування файла
            file_create(fullname);
            // функція створення файла
            cout << "File " << filename << " created." << endl;
            // виведення повідомлення про створення файла
            add_new_products(fullname);
            // функція додання продуктів
            cout << "\nOutput of this file: \n";
            read_file(fullname);
            // функція виводу вмісту файла
            adjust_prices(fullname);
            // функція корегування цін на продукти в залежності від їх терміну придатності
            cout << "Output of this file after adjustemnts: \n";
            read_file(fullname);
            // виведення оновленого файла
            copy_products_before_current_month(fullname, new_fullname);
            // функція створення нового файла з товарами виробленими раніше поточного місяця
            cout << "\nOutput of new file with products brefore current month: \n";
            read_file(new_fullname);
            // виведення вмісту нового файла
        } else {
            cout << "\nFile with name " << filename << " already exists" << endl;
            cout << "Output of this file: \n";
            // виведення повідомлення про існування файла
            do{
            read_file(fullname);
            // функція виводу вмісту файла
            cout << "\nPress y if you want to work with this file or press any other key to append it: ";
            cin >> check;
            // запит на додання нового товару
            if(check != 'y'){add_new_products(fullname);}
            // перевірка відповіді користувача
            }while(check != 'y');
            adjust_prices(fullname);
            // функція корегування цін на продукти в залежності від їх терміну придатності
            cout << "Output of this file after adjustemnts: \n";
            read_file(fullname);
            // виведення оновленого файла
            copy_products_before_current_month(fullname, new_fullname);
            // функція створення нового файла з товарами виробленими раніше поточного місяця
            cout << "\nOutput of new file with products brefore current month: \n";
            read_file(new_fullname);
            // виведення вмісту нового файла
        }
        cout << "\nPress (y) to try again: ";
        cin >> ch;
        // перевірка чи користувач хоче спробувати ще раз
    }while (ch == 'y');
}
