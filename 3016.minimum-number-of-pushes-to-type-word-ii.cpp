/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
      int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            ans += freq[i] * ((i / 8) + 1);
        }

        return ans;
    }
};
// @lc code=end

