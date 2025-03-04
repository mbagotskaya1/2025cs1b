#include<iostream>
using namespace std; 

int * getArray(int count){
    int * arr = new int[count];
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    return arr;
}

void printArray(int * a, int count) {
    for(int i = 0; i < count ; i++) {
        cout << *(a + i) << endl;
    }
}

int main()
{
    int * arr = getArray(3);
    printArray(arr, 3);
    delete[] arr;
}