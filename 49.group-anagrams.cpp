/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs)
        {
            vector<int> freq(26, 0);

            for (char c : s)
                freq[c - 'a']++;

            string key;
            for (int i : freq)
                key += to_string(i) + "*";

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &it : mp)
            ans.push_back(it.second);
        return ans;
    }
};
// @lc code=end
