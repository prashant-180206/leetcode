/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    vector<int> getnextvec(vector<int> &curr)
    {
        int n = curr.size();
        if (n == 0)
            return {1};
        if (n == 1)
            return {1, 1};

        vector<int> ans = {1};

        for (int i = 0; i < n - 1; i++)
            ans.push_back(curr[i] + curr[i + 1]);

        ans.push_back(1);
        return ans;
    }

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<int> prev = {};
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            auto curr = getnextvec(prev);
            ans.push_back(curr);
            prev = move(curr);
        }
        return ans;
    }
};
// @lc code=end
