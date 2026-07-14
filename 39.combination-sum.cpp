/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
    void helper(vector<vector<int>> &ans, vector<int> &arr, vector<int> &currentans, int target, int i)
    {
        if (target == 0)
        {
            ans.push_back(currentans);
            return;
        }
        if (target < 0)
            return;
        if (i == arr.size())
            return;
        // cloose single inclusion
        currentans.push_back(arr[i]);
        helper(ans, arr, currentans, target - arr[i], i);
        currentans.pop_back();
        // choose exclusion
        helper(ans, arr, currentans, target, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> currans;
        helper(ans, arr, currans, target, 0);
        return ans;
    }
};
// @lc code=end
