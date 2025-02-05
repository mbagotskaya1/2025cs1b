#include <iostream>
using namespace std;

int findMaxIn2DArray(int arr[5][5]) {
    int max = arr[0][0];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main() {
    int arr[5][5];

    cout << "enter elements of a 5x5 matrix: ";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "max is: " << findMaxIn2DArray(arr) << endl;
}