#include <iostream>
using namespace std; 

int find_threshold(int target, int i) {
    if (target <= 0) {
        return 0;
    }
    return 1 + find_threshold(target - i, i + 1);
}

int find_threshold(int target) {
    int n = 0;
    int i = 0;
    // while (n < target) {
    //     n += i;
    //     if (n >= target) {
    //         return i;
    //     }
    //     else {
    //         i++;
    //     }
    // }
    do {
        i++;
        n += i;
    } while (n < target);
    return i; 
}

int main() {

    int target;

    cout << "enter target number: ";
    cin >> target;

    cout << find_threshold(target) << endl;
    cout << find_threshold(target, 1) << endl;
}