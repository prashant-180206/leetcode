/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
    void addPermutations(vector<int> &arr, vector<vector<int>> &ans, int idx)
    {
        int n = arr.size();
        if (n == idx)
        {
            ans.push_back({arr});
            return;
        }
        for (int i = idx; i < n; i++)
        {
            swap(arr[i], arr[idx]);
            addPermutations(arr, ans, idx + 1);
            swap(arr[i], arr[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &arr)
    {
        vector<vector<int>> ans;
        addPermutations(arr, ans, 0);

        return ans;
    }
};
// @lc code=end
