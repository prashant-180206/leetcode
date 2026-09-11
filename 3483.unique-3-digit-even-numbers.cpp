/*
 * @lc app=leetcode id=3483 lang=cpp
 *
 * [3483] Unique 3-Digit Even Numbers
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int hundreds = 1; hundreds <= 9; hundreds++) {
            if (freq[hundreds] == 0) continue;

            freq[hundreds]--;

            for (int tens = 0; tens <= 9; tens++) {
                if (freq[tens] == 0) continue;

                freq[tens]--;

                for (int units : {0, 2, 4, 6, 8}) {
                    if (freq[units] > 0) {
                        ans++;
                    }
                }

                freq[tens]++;
            }

            freq[hundreds]++;
        }

        return ans;
    }
};

// @lc code=end

