/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> front(n, 0);

        for (int j = 0; j < n; j++)
            front[j] = arr[n - 1][j];
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int d = front[j] + arr[i][j];
                int dg = front[j + 1] + arr[i][j];
                curr[j] = min(d, dg);
            }
            front = curr;
        }

        return front[0];
    }
};
// @lc code=end
