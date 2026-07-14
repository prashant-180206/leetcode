/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
    void helper(vector<vector<int>> &ans, vector<int> &arr, vector<int> &curr, int target, int index)
    {

        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {

            // skip duplicates
            if (i > index && arr[i] == arr[i - 1])
                continue;

            // pruning
            if (arr[i] > target)
                break;

            curr.push_back(arr[i]);

            // move to next index (no reuse)
            helper(ans, arr, curr, target - arr[i], i + 1);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(arr.begin(), arr.end());

        helper(ans, arr, curr, target, 0);

        return ans;
    }
};
// @lc code=end
