/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
    bool dfs(vector<int> &sticks, int idx, vector<int> &sides, int target)
    {
        if (idx == sticks.size())
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;

        int stick = sticks[idx];

        for (int i = 0; i < 4; i++)
        {
            if (sides[i] + stick > target)
                continue;

            sides[i] += stick;

            if (dfs(sticks, idx + 1, sides, target))
                return true;

            sides[i] -= stick;
        }

        return false;
    }

public:
    bool makesquare(vector<int> &matchsticks)
    {
        int sum = accumulate(matchsticks.begin(),
                             matchsticks.end(), 0);

        if (sum % 4 != 0)
            return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);

        return dfs(matchsticks, 0, sides, target);
    }
};
// @lc code=end
