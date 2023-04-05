// Підключення потрібних заголовочних файлів, де оголошені класи та константи
#include <iostream>
#include "classes.h"
#include "constants.h"

using namespace std;

// Головна функція, де починається виконання програми
int main() {
    char ch;
    double x, y;
    do{
        // Виведення всіх прямих з масиву lines на екран
        lines[0].printAllLines(lines, n);
        // Запит координат точки від користувача
        cout << "\nEnter the coordinates of the point(x;y): ";
        cin >> x >> y;
        // Створення об'єкту Point з отриманими координатами
        Point p(x, y);
        // Знаходження всіх прямих з масиву lines, на яких лежить задана точка, та їх виведення на екран
        lines[0].findLineContainingPoint(lines, n, p);
        // Запит на повторення програми
        cout << "\n\nPress y to try again... ";
        cin >> ch;
} while(ch == 'y');// Повторення програми, якщо користувач ввів символ 'y'

return 0;   
}