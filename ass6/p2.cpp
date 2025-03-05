#include <iostream>
using namespace std;

int* mergeArrays(int* arr1, int size1, int* arr2, int size2) {
    int* mergedArr = new int[size1 + size2];
    int* ptr1 = arr1, *ptr2 = arr2, *ptrMerged = mergedArr;
    
    while (ptr1 < arr1 + size1 && ptr2 < arr2 + size2) {
        if (*ptr1 < *ptr2) {
            *ptrMerged = *ptr1;
            ptrMerged++;
            ptr1++;
        } else {
            *ptrMerged = *ptr2;
            ptrMerged++;
            ptr2++;
        }
    }
    while (ptr1 < arr1 + size1) {
        *ptrMerged = *ptr1;
        ptr1++;
        ptrMerged++;
    }
    while (ptr2 < arr2 + size2) {
        *ptrMerged = *ptr2;
        ptr2++;
        ptrMerged++;
    }
    return mergedArr;
}

int main() {
    
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = 3;
    int size2 = 3;
    
    int* mergedArr = mergeArrays(arr1, size1, arr2, size2);
    
    cout << "Merged Array: [";
    for (int i = 0; i < size1 + size2; i++) {
        cout << mergedArr[i] << (i < size1 + size2 - 1 ? ", " : "");
    }
    cout << "]" << endl;
    
    delete[] mergedArr;
}