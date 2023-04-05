#pragma once

class Point {
    private:
        double x, y;
    public:
        Point(double _x, double _y);
        double getX();
        double getY();
};

class Line {
    private:
        double a, b, c;
    public:
        Line(double _a, double _b, double _c);
        bool containsPoint(Point p);
        void printAllLines(Line lines[], const int n);
        void findLineContainingPoint(Line lines[], const int n, Point p);
};

