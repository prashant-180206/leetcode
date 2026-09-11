/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int arrayPairSum(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < arr.size(); i += 2)
        {
            sum += arr[i];
        }
        return sum;
    }
};
// @lc code=end
