/*
 * @lc app=leetcode id=3871 lang=cpp
 *
 * [3871] Count Commas in Range II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
    typedef long long ll;

public:
    ll countCommas(ll n)
    {

        ll ans = 0;

        for (ll p = 1000; p <= n; p *= 1000)
            ans += n - p + 1;

        return ans;
    }
};
// @lc code=end
