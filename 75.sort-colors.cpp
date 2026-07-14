/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            int current = arr[mid];
            if (current == 0)
                swap(arr[low++], arr[mid++]);
            else if (current == 1)
                mid++;
            else
                swap(arr[mid], arr[high--]);
        }
    }
};
// @lc code=end
