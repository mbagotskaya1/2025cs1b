#include <iostream>
using namespace std;

int nthDigit(int number, int n) {
    int temp = number;
    int count = 0;
    while (temp > 0) {
        count++;
        temp /= 10;
    }
    if (number == 0) return -1;
    for (int i = count; i > n; i--) {
        number /= 10;
    }
    return number % 10;
}

int main() {
    int number;
    int n;
    
    cout << "enter a number: ";
    cin >> number;
    cout << "enter digit position: ";
    cin >> n;

    cout << "the " << n << "th digit is: " << nthDigit(number, n) << endl;
}