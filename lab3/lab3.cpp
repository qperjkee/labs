#include <iostream>
#include "classes.h"
#include "constants.h"

using namespace std;

int main() {
    char ch;
    double x, y;
    do{
        lines[0].printAllLines(lines, n);
        cout << "\nEnter the coordinates of the point(x;y): ";
        cin >> x >> y;
        Point p(x, y);
        lines[0].findLineContainingPoint(lines, n, p);
        cout << "\n\nPress y to try again... ";
        cin >> ch;
} while(ch == 'y');

return 0;   
}