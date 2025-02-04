#include <iostream>
using namespace std; 

int sum_range(int start, int end, int z) { // z is here for overloading, for practice
    if (start == end) {
        return start;
    }
    return start + sum_range(start + 1, end, 0); // recursion
}

int sum_range(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int start;
    int end;

    cout << "enter start and end: ";
    cin >> start;
    cin >> end;

    cout << sum_range(start, end, 0) << endl; // recursive funnction 
    cout << sum_range(start, end) << endl;

}