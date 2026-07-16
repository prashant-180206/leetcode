/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    void dfs(vector<vector<int>> &img, int i, int j, int ogcol, int ncol)
    {
        if (i < 0 || j < 0 || i >= img.size() || j >= img[0].size() || img[i][j] == ncol || img[i][j] != ogcol)
            return;

        img[i][j] = ncol;
        dfs(img, i - 1, j, ogcol, ncol);
        dfs(img, i + 1, j, ogcol, ncol);
        dfs(img, i, j + 1, ogcol, ncol);
        dfs(img, i, j - 1, ogcol, ncol);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int ogcol = image[sr][sc];
        if (ogcol == color)
            return image;
        dfs(image, sr, sc, ogcol, color);
        return image;
    }
};
// @lc code=end
