// Merge sort (divide & conquer) on an array of integers.
//
// Compile: g++ -std=c++17 -O2 merge_sort_demo.cpp -o merge_sort
// Run:     ./merge_sort

#include <iostream>
#include <vector>

void merge(
    std::vector<int>& nums,
    int left,
    int mid,
    int right
) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    std::vector<int> leftArr(static_cast<std::size_t>(n1));
    std::vector<int> rightArr(static_cast<std::size_t>(n2));

    for (int i = 0; i < n1; ++i) {
        leftArr[static_cast<std::size_t>(i)] = nums[static_cast<std::size_t>(left + i)];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[static_cast<std::size_t>(j)] = nums[static_cast<std::size_t>(mid + 1 + j)];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[static_cast<std::size_t>(i)] <= rightArr[static_cast<std::size_t>(j)]) {
            nums[static_cast<std::size_t>(k)] = leftArr[static_cast<std::size_t>(i)];
            ++i;
        } else {
            nums[static_cast<std::size_t>(k)] = rightArr[static_cast<std::size_t>(j)];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        nums[static_cast<std::size_t>(k)] = leftArr[static_cast<std::size_t>(i)];
        ++i;
        ++k;
    }
    while (j < n2) {
        nums[static_cast<std::size_t>(k)] = rightArr[static_cast<std::size_t>(j)];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    const int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int main() {
    std::vector<int> nums{5, 2, 3, 1, 4, 9, 7, 8, 6};

    std::cout << "Original array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);

    std::cout << "Sorted array:   ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\n";

    return 0;
}

