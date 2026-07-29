/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
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
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; i++)
        {
            auto curr = getnextvec(prev);
            prev = move(curr);
        }

        return prev;
    }
};
// @lc code=end
