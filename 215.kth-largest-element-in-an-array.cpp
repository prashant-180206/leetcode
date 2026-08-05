/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
// @lc code=end
