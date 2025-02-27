#include<iostream>
using namespace std; 

int main()
{
    int arr[] = {11, 22, 33};
    int* ptr = arr;

    for(int i = 0; i < 3; i++) {
        cout << ptr[i] << " ";
        //cout << *(p + i) << " ";
    }
    cout << endl;
}