// Директива препроцесора, що гарантує, що даний заголовочний файл буде підключений до програми тільки один раз
#pragma once

// Клас Point для зберігання координат точки в просторі
class Point {
    private:
        double x, y;
    public:
        Point(double _x, double _y);// Конструктор класу Point
        double getX();// Метод для отримання координати x точки
        double getY();// Метод для отримання координати y точки
};

// Клас Line для зберігання рівняння прямої у вигляді ax + by + c = 0
class Line {
    private:
        double a, b, c;
    public:
        Line(double _a, double _b, double _c);// Конструктор класу Line
        bool containsPoint(Point p);// Метод для перевірки, чи належить точка прямій
        void printAllLines(Line lines[], const int n);// Метод для виведення на екран рівняння всіх прямих
        void findLineContainingPoint(Line lines[], const int n, Point p);// Метод для знаходження і виведення на екран номеру прямих, які проходять через точку p
};

