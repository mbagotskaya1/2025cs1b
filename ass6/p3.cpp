#include <iostream>
using namespace std;

void insertionSort(int* arr, int size) {
    for (int* ptr = arr; ptr < arr + size; ptr++) {
        int* insertPos = ptr; 
        int temp = *insertPos; 

        while (insertPos > arr && *(insertPos - 1) > temp) {
            *insertPos = *(insertPos - 1); 
            insertPos--; 
        }
        *insertPos = temp;
    }
}

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int size = 5;
    
    insertionSort(arr, size);
    
    cout << "Sorted Array: [";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    cout << "]" << endl;
}
