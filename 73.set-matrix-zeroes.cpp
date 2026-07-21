/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();

        bool haszeroinfirstrow = false;
        for (int i = 0; i < n; i++)
            if (arr[0][i] == 0)
            {
                haszeroinfirstrow = true;
                break;
            }

        bool haszeroinfirstcol = false;
        for (int i = 0; i < m; i++)
            if (arr[i][0] == 0)
            {
                haszeroinfirstcol = true;
                break;
            }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    arr[0][j] = 0;
                    arr[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (arr[0][j] == 0 || arr[i][0] == 0)
                    arr[i][j] = 0;

        if (haszeroinfirstrow)
            for (int i = 0; i < n; i++)
                arr[0][i] = 0;

        if (haszeroinfirstcol)
            for (int i = 0; i < m; i++)
                arr[i][0] = 0;
    }
};
// @lc code=end
