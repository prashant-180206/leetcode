/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
    void addSubset(vector<int> &arr, vector<vector<int>> &ans, vector<int> &currans, int i)
    {
        if (i >= arr.size())
        {
            ans.push_back(currans);
            return;
        }
        currans.push_back(arr[i]);
        addSubset(arr, ans, currans, i + 1);
        currans.pop_back();
        int idx = i + 1;
        while (idx < arr.size() && arr[idx] == arr[idx - 1])
            idx++;
        addSubset(arr, ans, currans, idx);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> currentans;
        sort(nums.begin(), nums.end());
        addSubset(nums, ans, currentans, 0);

        return ans;
    }
};
// @lc code=end
