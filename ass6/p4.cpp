#include <iostream>
#include <fstream>
using namespace std;

int*** allocate3DArray(int dim1, int dim2, int dim3) {
    int*** arr = new int**[dim1];
    for (int i = 0; i < dim1; i++) {
        arr[i] = new int*[dim2];
        for (int j = 0; j < dim2; j++) {
            arr[i][j] = new int[dim3];
        }
    }
    return arr;
}

void fill3DArray(int*** arr, int dim1, int dim2, int dim3) {
    ifstream file("data.txt");
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                file >> arr[i][j][k];
            }
        }
    }

    file.close();
}

void print3DArray(int*** arr, int dim1, int dim2, int dim3) {
    for (int i = 0; i < dim1; i++) {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    const int dim1 = 3; 
    const int dim2 = 4;
    const int dim3 = 5;

    int*** arr = allocate3DArray(dim1, dim2, dim3);
    fill3DArray(arr, dim1, dim2, dim3);
    print3DArray(arr, dim1, dim2, dim3);

    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}