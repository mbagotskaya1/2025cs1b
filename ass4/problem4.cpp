#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int findLongestConsecutive(int nums[], int size) {
    int longest = 1;
    int currentStreak = 1;

    for (int i = 1; i < size; i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        } else if (nums[i] == nums[i - 1] + 1) {
            currentStreak++;
        } else {
            if (currentStreak > longest) {
                longest = currentStreak;
            }
            currentStreak = 1; 
        }
    }
    if (currentStreak > longest) {
        longest = currentStreak;
    }
    return longest;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);
    insertionSort(nums, size);

    cout << "longest consecutive sequence length: " << findLongestConsecutive(nums, size) << endl;
    
    return 0;
}