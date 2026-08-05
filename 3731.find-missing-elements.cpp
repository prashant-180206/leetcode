/*
 * @lc app=leetcode id=3731 lang=cpp
 *
 * [3731] Find Missing Elements
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findMissingElements(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<int> ans;

        for (int i = 1; i < arr.size(); i++)
        {
            for (int x = arr[i - 1] + 1; x < arr[i]; x++)
                ans.push_back(x);
        }
        return ans;
    }
};
// @lc code=end
