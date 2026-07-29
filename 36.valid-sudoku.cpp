/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    bool isValidNum(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != col && board[row][i] == num)
                return false;

            if (i != row && board[i][col] == num)
                return false;

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if ((r != row || c != col) && board[r][c] == num)
                return false;
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                char c = board[row][col];
                if (c != '.')
                {
                    if (!isValidNum(board, row, col, c))
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
