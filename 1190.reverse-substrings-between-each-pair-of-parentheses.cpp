/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == ')')
            {
                string temp = "";
                while (!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop(); 
                for (char ch : temp)
                    st.push(ch);
            }
            else
            {
                st.push(c);
            }
        }

        string result = "";
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
