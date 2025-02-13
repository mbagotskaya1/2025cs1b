#include <iostream>
#include <fstream>
using namespace std;

void generateSortedArray(int a[], int size = 1000) {
    int value = 1;
    for(int i = 0; i< 1000; i++) {
        value += rand() % 7;
        a[i] = value;
    }
}

void storeInFile(int a[], int size = 1000, string fileName = "array0.txt") {
    ofstream f(fileName);
    for(int i = 0; i < 1000; i++) {
        f << a[i] << " ";
    }
    f.close();
}

void readFile(int a[], int size = 1000, string fileName = "array0.txt") {
    ifstream f(fileName);
    for (int i = 0; i < 1000; i++) {
        f >> a[i];
    }
    f.close();
}

int binSearchRec(int x, int a[], int start, int end, int size = 1000) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (x > a[mid]) {
        return binSearchRec(x, a, mid + 1, end);
    }
    else if (x < a[mid]) {
        return binSearchRec(x, a, start, mid - 1);
    }
    else {
        return mid;
    }
}

int binSearch(int x, int a[], int& numOfComparison, int size = 1000) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x == a[mid]) {
            return mid;
        }
        else if (x > a[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        numOfComparison++;
    }
    return -1;
}

int main() {

    int a[1000];
    readFile(a);
    int numOfComparison = 0;

    while(true) {
        int x;

        cout << "enter target number: ";
        cin >> x;
        int index = binSearch(x, a, numOfComparison);

        if(index >= 0) {
            cout << "number found at " << index << endl;
        }
        else {
            cout << "number not found" << endl;
        }
    }

    //generateSortedArray(a);
    //storeInFile(a);
}