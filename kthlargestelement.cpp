#include <iostream>
#include <vector>

using namespace std;

int findKthLargest(std::vector<int>& nums, int k) {
    // Ensure that k is a valid index within the array
    if (k < 1 || k > nums.size()) {
        cout << "Invalid value of k. Exiting..." << endl;
        exit(EXIT_FAILURE);
    }

    // Basic selection sort to find the kth largest element
    for (int i = 0; i < k; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] > nums[max_idx]) {
                max_idx = j;
            }
        }
        // Swap the elements
        int temp = nums[i];
        nums[i] = nums[max_idx];
        nums[max_idx] = temp;
    }

    return nums[k - 1];
}

int main() {
    std::vector<int> arr = {3, 1, 7, 5, 8, 2, 4, 6};
    int k = 4;

    int kth_largest = findKthLargest(arr, k);
    cout << "The " << k << "th largest element is: " << kth_largest << endl;

    return 0;
}
