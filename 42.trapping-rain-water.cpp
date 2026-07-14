/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &arr)
    {
        int n = arr.size();
        int lmax = 0, rmax = 0;
        int left = 0, right = n - 1;

        int ans = 0;

        while (left < right)
        {
            lmax = max(lmax, arr[left]);
            rmax = max(rmax, arr[right]);
            if (arr[left] <= arr[right])
            {
                ans += (lmax - arr[left]);
                left++;
            }
            else
            {
                ans += (rmax - arr[right]);
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
