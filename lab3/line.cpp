#include <iostream>
#include "classes.h"

using namespace std;

Line::Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
}

bool Line::containsPoint(Point p) {
    return (a * p.getX() + b * p.getY() + c == 0);
}

void Line::printAllLines(Line lines[], const int n) {
    cout << "\nAll lines: " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << lines[i].a << "x + " << lines[i].b << "y + " << lines[i].c << " = 0." << endl;
    }
}

void Line::findLineContainingPoint(Line lines[], const int n, Point p) {
    bool found = false;
    cout << "Point(" << p.getX() << ";" << p.getY() << ") belongs to: " << endl;
    for (int i = 0; i < n; i++) {
        if (lines[i].containsPoint(p)) {
            cout << i+1 << ". ";
            found = true;
        }
    }
    if (!found) {
        cout << "None of the ";
    }
    cout << "lines.";
}