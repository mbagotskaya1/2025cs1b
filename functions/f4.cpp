#include <iostream>
using namespace std; 

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

    cout << sum_range(start, end) << endl;

}