/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &arr)
    {

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            arr[i]++;
            if (arr[i] < 10)
                return arr;
            arr[i] = 0;
        }
        arr.insert(arr.begin(), 1);
        return arr;
    }
};
// @lc code=end
