/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> diffWaysToCompute(string expression) {

        if (dp.count(expression))
            return dp[expression];

        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {

            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {

                        if (ch == '+')
                            ans.push_back(l + r);
                        else if (ch == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }

        // Base case: expression is just a number
        if (ans.empty())
            ans.push_back(stoi(expression));

        return dp[expression] = ans;
    }
};
// @lc code=end

