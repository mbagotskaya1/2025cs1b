#include<iostream>
using namespace std; 

int findMax(int* arr) {
    int max = *arr; //value of the array
    for(int i = 1; i < 7; i++) {
        if(*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int* findMaxPtr(int* arr) {
    int* max = arr; //value of the first element of the array
    for(int i = 1; i < 7; i++) {
        if(*(arr + i) > *max) {
            max = (arr + i);
        }
    }
    return max;
}

int main() {

    int arr[7] = {1, 2, 22, 19, 14, 66, 3};
    int* max = findMaxPtr(arr);

    cout << "max element's address is " << max << " with a value " << findMax(arr) << endl;;
}