/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxval = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    maxval = max(maxval, i - st.top());
            }
        }
        return maxval;
    }
};
// @lc code=end
