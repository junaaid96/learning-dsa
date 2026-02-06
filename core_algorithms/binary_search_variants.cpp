// Binary search variants on a sorted array:
//   - standard search
//   - first occurrence
//   - last occurrence
//
// Compile: g++ -std=c++17 -O2 binary_search_variants.cpp -o binary_search
// Run:     ./binary_search

#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int firstOccurrence(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int answer = -1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            answer = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int lastOccurrence(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int answer = -1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            answer = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

int main() {
    const std::vector<int> nums{1, 2, 4, 4, 4, 5, 7, 9};
    const int target = 4;

    const int index = binarySearch(nums, target);
    const int first = firstOccurrence(nums, target);
    const int last = lastOccurrence(nums, target);

    std::cout << "Array: ";
    for (int value : nums) {
        std::cout << value << ' ';
    }
    std::cout << "\nTarget = " << target << "\n";

    std::cout << "Any occurrence index: " << index << "\n";
    std::cout << "First occurrence:     " << first << "\n";
    std::cout << "Last occurrence:      " << last << "\n";

    return 0;
}

