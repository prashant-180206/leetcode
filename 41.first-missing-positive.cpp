/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            if (arr[i] < 0)
                arr[i] = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = abs(arr[i]);
            if (curr >= 1 && curr <= n)
            {
                int idx = curr - 1;

                if (arr[idx] > 0)
                    arr[idx] *= -1;
                else if (arr[idx] == 0)
                    arr[idx] = -(n + 1);
            }
        }

        for (int i = 0; i < n; i++)
            if (arr[i] >= 0)
                return i + 1;

        return n + 1;
    }
};
// @lc code=end
