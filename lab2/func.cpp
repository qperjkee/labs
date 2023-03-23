#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

struct Product
{
    char name[100];
    char dateOfManufacture[11];
    char expirationDate[11];
    char price[10];
};
// створення структури товару

// Функція створення бінарного файлу
void file_create(string filename){
    ofstream created_file(filename, ios::binary); // створюємо новий файл з іменем, що передано як параметр
    created_file.close(); // закриваємо файл
}

// Функція для зчитування бінарного файлу з ім'ям filename
void read_file(string filename){

    // Відкриваємо файл в бінарному режимі
    ifstream file(filename, ios::binary);

    // Створюємо об'єкт типу Product для зчитування даних про продукт
    Product product;

    // Починаємо читати дані про продукти з файлу і виводити їх на екран
    while(file.read((char*)&product, sizeof(Product))){
        cout << "Product name: " << product.name << ", " 
             << "Date of manufacture: " << product.dateOfManufacture << ", "
             << "Expiration date: " << product.expirationDate << ", "
             << "Price: " << product.price << "$"<<endl;
    }

    // Закриваємо файл після виконання операції зчитування
    file.close();
}

// Функція для визначення, чи є рік високосним
char is_year_leap(int year) {
    // Рік буде високосним, якщо:
    // - Він не кратний 100, але кратний 4, або
    // - Він кратний 400
    return ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0);
}

// Функція для перевірки правильності формату дати та коректності введеного дня
bool check_date(string date){

    int day, month, year;

    // Спробуємо витягнути день, місяць та рік з рядка за допомогою функції sscanf_s()
    sscanf_s(date.c_str(), "%d/%d/%d", &day, &month, &year);

    // Перевіряємо, чи коректна кількість днів у лютому в залежності від року
    if (month == 2) {
        if (day <= 28 + is_year_leap(year)){ // Викликаємо функцію is_year_leap() для визначення, чи високосний рік
            return true;
        }
        else{
            printf("Februrary has only 28 days!\n\n"); // Повідомляємо користувача про помилку
            return false;
        }
    }

    // Перевіряємо, чи коректна кількість днів у місяцях, крім лютого
    if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day > 30){
            printf("There is only 30 days in this month!\n\n"); // Повідомляємо користувача про помилку
            return false;
        }
        else{
            return true;
        }
    }

    // Якщо дата введена правильно, повертаємо true
    return true;
}

// Функція для порівняння двох дат
bool compare_dates(string date1, string date2){

    int day, month, year, day2, month2, year2;

    // Витягуємо день, місяць та рік першої дати
    sscanf_s(date1.c_str(), "%d/%d/%d", &day, &month, &year);

    // Витягуємо день, місяць та рік другої дати
    sscanf_s(date2.c_str(), "%d/%d/%d", &day2, &month2, &year2);

    // Порівнюємо різні компоненти дат, якщо перша дата не більша або рівна другій, повертаємо true
    if(day <= day2 && month <= month2 && year <= year2 || day >= day2 && month <= month2 && year <= year2 || day >= day2 && month >= month2 && year <= year2 || day <= day2 && month >= month2 && year <= year2){
        return true;
    }
    else{
        cout << "Date error!"; // Якщо перша дата більша за другу, виводимо повідомлення про помилку
        return false;
    }
}

// Функція додання продукту до файлу
void add_new_products(string filename){
    ofstream file(filename, ios::app | ios::binary); // відкриваємо файл у режимі додавання
    Product product; // створюємо об'єкт структури Product
    char ch;
    do{
        cin.ignore(); // очищуємо буфер вводу
        cout << "\nEnter product name: ";
        fgets(product.name, sizeof(product.name), stdin); // отримуємо назву продукту

        product.name[strcspn(product.name, "\n")] = '\0'; // видаляємо символ нового рядка з кінця рядка
        do{
        do{
            cout << "\nEnter date Of manufacture(DD/MM/YYYY): ";
            fgets(product.dateOfManufacture, sizeof(product.dateOfManufacture), stdin); // отримуємо дату виготовлення

            product.dateOfManufacture[strcspn(product.dateOfManufacture, "\n")] = '\0'; // видаляємо символ нового рядка з кінця рядка
        }while(!check_date(product.dateOfManufacture)); // перевіряємо, чи коректна введена дата виготовлення

        do{
            cout << "\nEnter product expiration date(DD/MM/YYYY): ";
            fgets(product.expirationDate, sizeof(product.expirationDate), stdin); // отримуємо дату придатності

            product.expirationDate[strcspn(product.expirationDate, "\n")] = '\0'; // видаляємо символ нового рядка з кінця рядка
        }while(!check_date(product.expirationDate)); // перевіряємо, чи коректна введена дата придатності
        }while(!compare_dates(product.dateOfManufacture, product.expirationDate)); // перевіряємо, чи дата виготовлення раніша за дату придатності

        cout << "\nEnter product price in $: ";
        fgets(product.price, sizeof(product.price), stdin); // отримуємо ціну продукту

        product.price[strcspn(product.price, "\n")] = '\0'; // видаляємо символ нового рядка з кінця рядка

        file.write((char*)&product, sizeof(Product)); // записуємо об'єкт структури Product у файл
        cout << "Do you want to add more(y): ";
        cin >> ch;
    } while(ch == 'y'); // перевіряємо, чи користувач бажає додати ще продукт
    file.close(); // закриваємо файл
}

// Функція для розрахунку кількості днів до терміну придатності продукту
int calculate_days_till_expiration(string dateOfManufacture, string expirationDate){

    struct tm t1 = {0}; // Структура для зберігання дати виробництва
    struct tm t2 = {0}; // Структура для зберігання дати терміну придатності продукту
    int year, month, day;

    // Розбираємо дату виробництва та зберігаємо її в структурі tm
    sscanf_s(dateOfManufacture.c_str(), "%d/%d/%d", &day, &month, &year);
    t1.tm_year = year - 1900;
    t1.tm_mon = month - 1;
    t1.tm_mday = day;

    // Розбираємо дату терміну придатності продукту та зберігаємо її в структурі tm
    sscanf_s(expirationDate.c_str(), "%d/%d/%d", &day, &month, &year);
    t2.tm_year = year - 1900;
    t2.tm_mon = month - 1;
    t2.tm_mday = day;

    // Обчислюємо час, який пройшов між датами в секундах
    time_t expiration_time = mktime(&t2);
    time_t now = mktime(&t1);
    double seconds_left = difftime(expiration_time, now);

    // Перетворюємо секунди в дні та повертаємо кількість днів до терміну придатності продукту
    int days_left = static_cast<int>(seconds_left / 86400); 
    return days_left;
}

// Функція для зміни цін продуктів в файлі
void adjust_prices(string filename){

    ifstream read_file(filename, ios::binary); // Відкриваємо вхідний файл для читання
    ofstream write_file("temp.bin", ios::binary); // Відкриваємо тимчасовий файл для запису
    Product product;

    // Проходимо через усі записи у вхідному файлі
    while(read_file.read((char*)&product, sizeof(Product))){

        // Розраховуємо кількість днів до терміну придатності продукту
        int days_till_expiration = calculate_days_till_expiration(product.dateOfManufacture, product.expirationDate);

        // Перетворюємо рядок ціни продукту у змінну типу double
        double price = atof(product.price);

        // Змінюємо ціну в залежності від кількості днів до терміну придатності
        if(days_till_expiration <= 14){
            price *= 0.95; // Зменшуємо ціну на 5%
        } else if(days_till_expiration >= 365){
            price *= 1.03; // Збільшуємо ціну на 3%
        }

        // Зберігаємо нову ціну у рядок продукту
        snprintf(product.price, sizeof(product.price), "%.2lf", price);

        // Записуємо оновлений запис у тимчасовий файл
        write_file.write((char*)&product, sizeof(Product));
    }

    // Закриваємо файли та замінюємо вихідний файл тимчасовим
    read_file.close();
    write_file.close();
    remove(filename.c_str());
    rename("temp.bin", filename.c_str());
}

// Функція для копіювання записів продуктів з вхідного файлу в вихідний файл, які були виготовлені до поточного місяця включно
void copy_products_before_current_month(const string& input_filename, const string& output_filename) {
  // Відкриваємо вхідний та вихідний файли
  ifstream input_file(input_filename, ios::binary);
  ofstream output_file(output_filename, ios::binary);

  // Отримуємо поточну дату
  time_t now = time(nullptr);
  tm local_time = *localtime(&now);
  int current_month = local_time.tm_mon + 1;
  int current_year = local_time.tm_year + 1900;

  Product product;
  while (input_file.read(reinterpret_cast<char*>(&product), sizeof(Product))) {

    // Отримуємо дату виготовлення продукту
    string date_str(product.dateOfManufacture);
    size_t first_slash_pos = date_str.find('/');
    size_t second_slash_pos = date_str.find('/', first_slash_pos + 1);
    string month_str = date_str.substr(0, first_slash_pos);
    string year_str = date_str.substr(second_slash_pos + 1);
    int product_month = stoi(month_str);
    int product_year = stoi(year_str);

    // Якщо продукт був виготовлений до поточного місяця включно, то копіюємо його в вихідний файл
    if ((product_year < current_year) || (product_year == current_year && product_month < current_month)) {
      output_file.write(reinterpret_cast<char*>(&product), sizeof(Product));
    }
  }

  // Закриваємо файли
  input_file.close();
  output_file.close();
}


