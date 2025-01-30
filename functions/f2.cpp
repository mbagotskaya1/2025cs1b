#include <iostream>
using namespace std;

void power(int base, int exponent, float& res) {
    float b = base;
    if(exponent < 0) {
        b = 1 / (float)b;
        exponent *= -1;
    }
    if(exponent == 0) {
        res = 1;
    }
    res = b;
    while(exponent > 1) {
        res = res * b;
        exponent--;
    }
}

float powRec(int b, int e) {
    // let's assume e >= 1
    if (e == 1) {
        return b;
    }
    else {
        return b * powRec(b, e - 1);
    }
}

int main() {
    int base;
    int exponent;

    cout << "enter the base and exponent: ";
    cin >> base;
    cin >> exponent;

    float res;
    power(base, exponent, res);

    cout << res << endl;
}