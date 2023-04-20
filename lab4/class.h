#pragma once

class Vector2D{
    private:
        double x, y;
    public:
        Vector2D();
        Vector2D(double _x, double _y);
        Vector2D(double _x);
        double getX();
        double getY();
        double getLength();
        Vector2D operator-(const Vector2D& other) const;
        Vector2D& operator*(const double mult);
};

double getNumericInput();