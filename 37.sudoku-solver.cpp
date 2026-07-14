/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{

    bool isSafe(vector<vector<char>> &board, int row, int col, char dig)
    {
        // check in same row
        for (int i = 0; i < 9; i++)
            if (board[row][i] == dig)
                return false;
        // check in same col
        for (int i = 0; i < 9; i++)
            if (board[i][col] == dig)
                return false;
        // check in box
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i <= sr + 2; i++)
            for (int j = sc; j <= sc + 2; j++)
                if (board[i][j] == dig)
                    return false;

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
            return true;
        int nextRow = row;
        int nextCol = col + 1;
        if (nextCol == 9)
        {
            nextRow += 1;
            nextCol = 0;
        }

        if (board[row][col] != '.')
            return helper(board, nextRow, nextCol);
        for (char i = '1'; i <= '9'; i++)
        {
            if (isSafe(board, row, col, i))
            {
                board[row][col] = i;
                if (helper(board, nextRow, nextCol))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board, 0, 0);
    }
};
// @lc code=end
