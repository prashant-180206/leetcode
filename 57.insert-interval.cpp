/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &arr, vector<int> &insert)
    {
        int n = arr.size();
        vector<vector<int>> ans;

        int i = 0;

        while (i < n && arr[i][1] < insert[0])
        {
            ans.push_back(arr[i]);
            i++;
        }

        while (i < n && arr[i][0] <= insert[1])
        {
            insert[0] = min(insert[0], arr[i][0]);
            insert[1] = max(insert[1], arr[i][1]);
            i++;
        }
        ans.push_back(insert);

        while (i < n)
        {
            ans.push_back(arr[i]);
            i++;
        }

        return ans;
    }
};
// @lc code=end
