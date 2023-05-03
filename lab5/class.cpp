#include "class.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

TNumber::TNumber(double n) {
    num = n;
}

double TNumber::getNum() {
    return num;
}

void TNumber::sumNum(TNumber* numberArray, int size){
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numberArray[i].findNum();
    }
    cout << "Sum of digits: " << sum << endl;
}

TIntNumber::TIntNumber() : TNumber(0) {}

TIntNumber::TIntNumber(int n) : TNumber((double)n) {}

void TIntNumber::init(int m) {
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        this[i] = TIntNumber(rand() % 1000 + 1);
        cout << i + 1 << " = " << this[i].getNum() << endl;
    }
}

int TIntNumber::findNum() {
    double n = getNum();
    while (n >= 10) {
        n /= 10;
    }
    return (int)n;
}

TRealNumber::TRealNumber() : TNumber(0) {}

TRealNumber::TRealNumber(double n) : TNumber(n) {}

void TRealNumber::init(int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        this[i] = TRealNumber(round((double)rand() / (double)RAND_MAX * 100000) / 100);
        cout << i + 1 << " = " << this[i].getNum() << endl;
    }
}

int TRealNumber::findNum() {
    string str_n = to_string(getNum());
    size_t pos = str_n.find('.');

    if (pos != string::npos && str_n.length() > pos + 2) {
        str_n.erase(pos + 3);
    }

    int last = str_n.back() - '0';
    return last ? last : str_n[str_n.length() - 2] - '0';
}