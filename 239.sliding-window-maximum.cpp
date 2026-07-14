/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

#include <vector>
#include <deque>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        vector<int> result;
        deque<int> dq;
        // dq.push_back(arr[0]);

        for (int i = 0; i < k; i++)
        {
            while (dq.size() > 0 && arr[dq.back()] < arr[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k; i < arr.size(); i++)
        {
            result.push_back(arr[dq.front()]);

            // check if element is of current window
            while (dq.size() > 0 && dq.front() <= i - k)
                dq.pop_front();

            while (dq.size() > 0 && arr[dq.back()] < arr[i])
                dq.pop_back();
                
            dq.push_back(i);
        }

        result.push_back(arr[dq.front()]);

        return result;
    }
};
// @lc code=end
