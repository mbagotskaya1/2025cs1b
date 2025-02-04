#include <iostream>
using namespace std; 

int find_gcd_rec(int n1, int n2) {
    if (n1 == 0) {
        return n2;
    }
    return find_gcd_rec(n2 % n1, n1);
}

int find_gcd(int n1, int n2) {
    int res;
    int temp;
    while (n1 != 0) {
        temp = n1;
        n1 = n2 % n1;
        n2 = temp;
    }
    return n2;
}

int main() {

    int n1;
    int n2;

    cout << "enter two positive numbers: ";
    cin >> n1 >> n2;

    cout << find_gcd(n1, n2) << endl;
    cout << find_gcd_rec(n1, n2) << endl;
}