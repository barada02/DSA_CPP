#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Step 1: Sort the array. 
        // In C++, std::sort uses O(n log n) time.
        std::sort(nums.begin(), nums.end());

        // Step 2: Iterate through the sorted array.
        // We stop at nums.size() - 1 so we don't go out of bounds.
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            // Check if the current element is the same as the next one
            if (nums[i] == nums[i + 1]) {
                return true; 
            }
        }

        // No adjacent duplicates found
        return false;
    }
};