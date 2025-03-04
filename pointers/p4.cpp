#include<iostream>
using namespace std; 

int findMax(int* arr) {
    int max = *arr;
    for(int i = 1; i < 7; i++) {
        if(*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {

    int arr[7] = {1, 2, 22, 19, 14, 66, 3};
    int max = findMax(arr);

    cout << "max element is " << max << endl;
}