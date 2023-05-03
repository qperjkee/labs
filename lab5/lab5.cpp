#include <iostream>
#include "class.h"

using namespace std;

int main() {
    int m, n;

    cout << "Enter amount of integers to generate: ";
    cin >> m;

    TNumber* p = new TIntNumber[m];
    p->init(m);

    TNumber::sumNum(p, m);

    cout << "Enter amount of real numbers to generate: ";
    cin >> n;

    delete[] p;
    p = new TRealNumber[n];
    p->init(n);

    TNumber::sumNum(p, n);

    delete[] p;

    return 0;
}