/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &arr)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = arr[slow];
            fast = arr[arr[fast]];

        } while (slow != fast);

        slow = 0;

        while (slow != fast)
        {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};
// @lc code=end
