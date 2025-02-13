#include <iostream>
using namespace std;

void printArray(int a[], int size = 1000) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    int a[6] = {1,6,2,5,3,2};
    bool found = false;

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (a[i] == a[j]) {
                cout << a[i] << endl;
                return 0;
            }
        }
    }
}