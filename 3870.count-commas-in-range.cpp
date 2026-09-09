/*
 * @lc app=leetcode id=3870 lang=cpp
 *
 * [3870] Count Commas in Range
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution
{
public:
    int countCommas(int n)
    {
        return max(0, n - 999);
    }
};
// @lc code=end
