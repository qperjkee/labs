#include <iostream>
#include <string>
#include <cmath>
#include "class.h"

using namespace std;

Vector2D::Vector2D(){
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double _x, double _y){
    x = _x;
    y = _y;
}

Vector2D::Vector2D(double _x) {
    x = _x;
    y = 2;
}

double Vector2D::getX(){
    return x;   
}

double Vector2D::getY(){
    return y;
}

double Vector2D::getLength(){
    return sqrt(x * x + y * y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const{
    return Vector2D(x - other.x, y - other.y);  
}

Vector2D& Vector2D::operator*(const double mult) {
    x *= mult;
    y *= mult;
    return *this;
}

double getNumericInput() {
    double input;
    string str;
    while(true) {
        cin >> str;
        bool valid_input = true;
        for (int i = 0; i < str.length(); i++) {
            if (!(isdigit(str[i]) || str[i] == '.' || (i==0 && str[i] == '-'))) {
                valid_input = false;
                break;
            }
        }
        if (valid_input) {
            input = stod(str);
            return input;
        } else {
            cout << "ERROR - only numeric input!\nEnter correct number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}