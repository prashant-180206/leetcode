/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    void helper(int num, int n, int k, vector<int> &curr, int depth, vector<vector<int>> &ans)
    {
        if (depth == k)
        {
            ans.push_back(curr);
            return;
        }
        for (int i = num + 1; i <= n; i++)
        {
            curr.push_back(i);
            helper(i, n, k, curr, depth + 1, ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(0, n, k, curr, 0, ans);

        return ans;
    }
};
// @lc code=end
