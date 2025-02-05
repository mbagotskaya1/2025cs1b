#include <iostream>
using namespace std;

bool isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        return true;
    }
    return false;
}

int main() {
     int n;

     cout << "enter number: ";
     cin >> n;

     if (isPerfectNumber(n)) {
        cout << "the number is perfect";
     }
     if (!isPerfectNumber(n)) {
        cout << "the number is not perfect";
     }
}