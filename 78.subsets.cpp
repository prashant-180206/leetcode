/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    void addSubset(vector<int> &arr, vector<vector<int>> &ans, vector<int> &currans, int i)
    {
        if (i == arr.size())
        {
            ans.push_back(currans);
            return;
        }
        currans.push_back(arr[i]);
        addSubset(arr, ans, currans, i + 1);
        currans.pop_back();
        addSubset(arr, ans, currans, i + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> currentans;
        addSubset(nums, ans, currentans, 0);

        return ans;
    }
};
// @lc code=end
