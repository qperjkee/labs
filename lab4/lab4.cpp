#include <iostream>
#include "class.h"

using namespace std;

int main(){
    double x, y, x2;
    char ch;
    do{
        cout << "Enter x coordinate of first vector : ";
        x = getNumericInput();
        cout << "Enter y coordinate of first vector : ";
        y = getNumericInput();
        cout << "Enter x coordinate of second vector : ";
        x2 = getNumericInput();
        
        Vector2D V1(x, y);
        Vector2D V2(x2);
        Vector2D V3;

        cout << "V1 = (" << V1.getX() << ", " << V1.getY() << ")" << endl;
        V1 * 2;
        V3 = V1 - V2;

        cout << "V2 = (" << V2.getX() << ", " << V2.getY() << ")" << endl;
        cout << "V1_doubled = (" << V1.getX() << ", " << V1.getY() << ")" << endl;
        cout << "V3 = (" << V3.getX() << ", " << V3.getY() << ")" << endl;
        cout << "Length of V3 = " << V3.getLength() << endl;
        cout << "Press 'y' if you want to try again... ";
        cin >> ch;
    }while(ch == 'y');

    return 0;
}