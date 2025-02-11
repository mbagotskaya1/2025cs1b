#include <iostream>
using namespace std;

void printArray(float arr[10]) {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void shiftArray(float arr[10], int x) {
    int i = 0;
    int sourceIndex = 0;
    while (i < 10) {
        int destIndex = (sourceIndex + x) % 10;
        float tenp = arr[destIndex];
        arr[destIndex] = arr[sourceIndex];
        sourceIndex = destIndex;
        i++;
    }
    float tempNum = (9 + x) % 10;
    for (int i = 9; i > 0; i--) {
        int index = (i + x) % 10;
        arr[index] = arr[i];
    }
    int index = ((9 + x) % 10 + x) % 10;
    arr[index] = tempNum;
}

int main() {
    float arr[] = {12.3, 1.4, 3.3, 9.5, 1.9, 13.3, 20, 29, 15.59, 10};
    cout << "enter number (shift count): ";
    int x;
    cin >> x;
    printArray(arr);
    shiftArray(arr, x);
    printArray(arr);
}