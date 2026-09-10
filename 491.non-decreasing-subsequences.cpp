/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
    vector<vector<int>> ans;

    void helper(vector<int> &arr, int idx, vector<int> &curr)
    {
        if (curr.size() >= 2)
            ans.push_back(curr);

        set<int> used;

        for (int i = idx; i < arr.size(); i++)
        {
            if (used.count(arr[i]))
                continue;

            used.insert(arr[i]);

            if (curr.empty() || arr[i] >= curr.back())
            {
                curr.push_back(arr[i]);

                helper(arr, i + 1, curr);

                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        ans.clear();

        vector<int> curr;
        helper(nums, 0, curr);

        return ans;
    }
};
// @lc code=end
