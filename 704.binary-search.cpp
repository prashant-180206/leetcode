/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int start = 0, end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};
// @lc code=end
