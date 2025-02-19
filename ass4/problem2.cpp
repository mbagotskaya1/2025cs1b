#include <iostream>
using namespace std;

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "[" << i << ", " << j << "]" << endl;
                return 0;
            }
        }
    }
}