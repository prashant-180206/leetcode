/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
    bool isSafe(vector<string> &board, int n, int idx, int rowpos)
    {
        // in col
        for (int i = 0; i < idx; i++)
        {
            if (board[i][rowpos] == 'Q')
                return false;
        }
        // in diagonal
        for (int i = idx, j = rowpos; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // in diagonal other
        for (int i = idx, j = rowpos; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void nQueens(int &ans, vector<string> &board, int n, int idx)
    {
        if (idx == n)
        {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(board, n, idx, i))
            {
                board[idx][i] = 'Q';
                nQueens(ans, board, n, idx + 1);
                board[idx][i] = '.';
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        nQueens(ans, board, n, 0);
        return ans;
    }
};
// @lc code=end
