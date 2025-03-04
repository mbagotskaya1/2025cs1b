#include<iostream>
using namespace std; 

void printArray(char* arr) {
    for(int i = 0; i < 11 ; i++) {
        cout << *arr;
        arr++;
    }
    cout << endl;
}

int main() {

    char arr[11] = "saddleback";
    printArray(arr);
}