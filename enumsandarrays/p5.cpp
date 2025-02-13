#include <iostream>
using namespace std;

int main() {
    int a[] = {3, -1, -1, 10, -3, -2, 4};
    int max = a[0];
    for (int start = 0; start < 7; start++) {
        for (int end = start; end < 7; end++) {
            int sum = 0;
            for (int i = start; i <= end; i++) {
                sum += a[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
    }
    cout << max << endl;
}