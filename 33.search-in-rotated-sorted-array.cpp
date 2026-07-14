/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int search(vector<int> &A, int target)
    {
        int n = A.size();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (A[mid] == target)
                return mid;
            
            // Left Sorted
            if (A[start] <= A[mid])
            {
                if (A[start] <= target && A[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                // Right Sorted
                if (A[mid] < target && A[end] >= target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
