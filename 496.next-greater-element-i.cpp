/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        unordered_map<int, int> map;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int elem = nums2[i];
            while (!st.empty() && st.top() <= elem)
            {
                st.pop();
            }
            map[elem] = st.empty() ? -1 : st.top();
            st.push(elem);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};
// @lc code=end
