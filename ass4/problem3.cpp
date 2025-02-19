#include <iostream>
using namespace std;

int findMissingNumber(int n[], int size) {
    int expectedSum = 0;
    int sum = 0;

    for (int i = 0; i <= size; i++) {
        expectedSum += i;
    }

    for (int j = 0; j < size; j++) {
        sum += n[j];
    }
    return expectedSum - sum;
}

int main() {

    int n[] = {3, 0, 1};
    int size = sizeof(n) / sizeof(n[0]); // Number of elements

    cout << "missing number: " << findMissingNumber(n, size) << endl;
    
}