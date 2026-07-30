/*
 * @lc app=leetcode id=3014 lang=cpp
 *
 * [3014] Minimum Number of Pushes to Type Word I
 */
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<int> counts;
        for (const auto& pair : freq) {
            counts.push_back(pair.second);
        }
        sort(counts.begin(), counts.end(), greater<int>());

        int totalPushes = 0;
        for (int i = 0; i < counts.size(); i++) {
            int pushes = (i / 8) + 1;
            totalPushes += counts[i] * pushes;
        }

        return totalPushes;
    }
};
// @lc code=end

