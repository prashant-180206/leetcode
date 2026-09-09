/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int cand1 = 0, cand2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int x : arr)
        {
            if (x == cand1)
                cnt1++;
            else if (x == cand2)
                cnt2++;
            else if (cnt1 == 0)
            {
                cand1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                cand2 = x;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        // verification
        cnt1 = 0;
        cnt2 = 0;

        for (int x : arr)
        {
            if (x == cand1)
                cnt1++;
            else if (x == cand2)
                cnt2++;
        }

        vector<int> ans;
        int n = arr.size();

        if (cnt1 > n / 3)
            ans.push_back(cand1);
        if (cnt2 > n / 3)
            ans.push_back(cand2);

        return ans;
    }
};
// @lc code=end
