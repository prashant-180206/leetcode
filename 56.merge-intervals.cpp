/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        if (arr.size() == 1)
            return arr;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int i = 0;

        while (i < arr.size())
        {
            int start = arr[i][0];
            int end = arr[i][1];

            while (i + 1 < arr.size() && arr[i + 1][0] <= end)
            {
                end = max(end, arr[i + 1][1]);
                i++;
            }

            ans.push_back({start, end});
            i++;
        }

        return ans;
    }
};
// @lc code=end
