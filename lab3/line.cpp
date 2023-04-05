// Підключаємо потрібні бібліотеки
#include <iostream>
#include "classes.h"

using namespace std;

// Конструктор класу Line, що ініціалізує коефіцієнти a, b, c
Line::Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
}

// Метод класу Line, що перевіряє, чи належить точка прямій
bool Line::containsPoint(Point p) {
    return (a * p.getX() + b * p.getY() + c == 0);// Повертає true, якщо точка належить прямій, false - якщо ні
}

// Метод класу Line, що виводить на екран рівняння всіх прямих з масиву lines
void Line::printAllLines(Line lines[], const int n) {
    cout << "\nAll lines: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << lines[i].a << "x + " << lines[i].b << "y + " << lines[i].c << " = 0." << endl;
    }
}

// Метод класу Line, що знаходить та виводить на екран всі прямі з масиву lines, які проходять через точку p
void Line::findLineContainingPoint(Line lines[], const int n, Point p) {
    bool found = false;
    cout << "Point(" << p.getX() << ";" << p.getY() << ") belongs to: " << endl;
    for (int i = 0; i < n; i++) {
        if (lines[i].containsPoint(p)) {
            cout << i+1 << ". ";// Номер прямої
            found = true;
        }
    }
    if (!found) {
        cout << "None of the ";// Якщо жодна пряма не проходить через точку
    }
    cout << "lines.";
}