/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        // Return the kth element (k is 1-indexed)
        return nums[k - 1];

    }
};
// @lc code=end

