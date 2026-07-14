/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();

        int start = 1, end = n - 2;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid])
                return mid;

            if (arr[mid - 1] < arr[mid + 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
// @lc code=end
