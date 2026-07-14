/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        int start = 0, end = n - 1;

        if (n == 1)
            return arr[0];

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid == 0 && arr[mid] != arr[mid + 1])
                return arr[mid];
            if (mid == n - 1 && arr[mid] != arr[mid - 1])
                return arr[mid];

            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
                return arr[mid];

            if (mid % 2 == 0)
            {
                if (arr[mid] == arr[mid + 1])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (arr[mid] == arr[mid + 1])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
