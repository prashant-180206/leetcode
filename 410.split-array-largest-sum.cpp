/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
    int getPossibleDivisionCount(vector<int> &arr, int maxsum)
    {
        int div = 1, currentsum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if ((currentsum + arr[i]) > maxsum)
            {
                div++;
                currentsum = arr[i];
            }
            else
            {
                currentsum += arr[i];
            }
        }

        return div;
    }

public:
    int splitArray(vector<int> &arr, int divisions)
    {
        if (arr.size() < divisions)
            return -1;
        int end = 0, start = INT_MIN;
        for (int val : arr)
        {
            start = max(start, val);
            end += val;
        }

        int ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int thisdivisons = getPossibleDivisionCount(arr, mid);

            if (thisdivisons <= divisions)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
