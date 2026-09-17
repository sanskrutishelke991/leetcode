#include <vector>
#include <algorithm>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int target) {
        // Step 1: Sort the array to use the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        // Step 2: Shrink the window from both ends
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                // If the sum is less than target, all elements between 
                // left and right will also form a valid pair with nums[left].
                ans += (right - left);
                left++; // Move left pointer to increase the sum
            } else {
                right--; // Move right pointer to decrease the sum
            }
        }
        
        return ans;
    }
};
