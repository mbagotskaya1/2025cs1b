#include <iostream>
using namespace std;

int remove_duplicates(int arr[5]) {
    int count = 0;
    int size = 0;
    for (int j = 0; j < 5; j++) {
        size++;
    }
    for (int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
    }
    return size - count;
}

int main() {
    int arr[5] = {1, 2, 1, 3, 4};
    cout << remove_duplicates(arr) << endl;
}