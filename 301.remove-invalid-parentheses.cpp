/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    unordered_set<string> result;

    void dfs(
        const string &s,
        int index,
        int leftRemove,
        int rightRemove,
        int balance,
        string &current)
    {
        // Invalid prefix
        if (balance < 0)
            return;

        // Reached the end
        if (index == s.size())
        {
            if (balance == 0 &&
                leftRemove == 0 &&
                rightRemove == 0)
            {
                result.insert(current);
            }
            return;
        }

        char ch = s[index];

        // Parenthesis
        if (ch == '(')
        {

            // Option 1: remove '('
            if (leftRemove > 0)
            {
                dfs(
                    s,
                    index + 1,
                    leftRemove - 1,
                    rightRemove,
                    balance,
                    current);
            }

            // Option 2: keep '('
            current.push_back('(');

            dfs(
                s,
                index + 1,
                leftRemove,
                rightRemove,
                balance + 1,
                current);

            current.pop_back();
        }
        else if (ch == ')')
        {

            // Option 1: remove ')'
            if (rightRemove > 0)
            {
                dfs(
                    s,
                    index + 1,
                    leftRemove,
                    rightRemove - 1,
                    balance,
                    current);
            }

            // Option 2: keep ')'
            if (balance > 0)
            {
                current.push_back(')');

                dfs(
                    s,
                    index + 1,
                    leftRemove,
                    rightRemove,
                    balance - 1,
                    current);

                current.pop_back();
            }
        }
        else
        {
            // Letters are always kept
            current.push_back(ch);

            dfs(
                s,
                index + 1,
                leftRemove,
                rightRemove,
                balance,
                current);

            current.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find the minimum number of removals required
        for (char ch : s)
        {

            if (ch == '(')
            {
                leftRemove++;
            }
            else if (ch == ')')
            {

                if (leftRemove > 0)
                {
                    leftRemove--;
                }
                else
                {
                    rightRemove++;
                }
            }
        }

        string current;

        dfs(
            s,
            0,
            leftRemove,
            rightRemove,
            0,
            current);

        return vector<string>(result.begin(), result.end());
    }
};
// @lc code=end
