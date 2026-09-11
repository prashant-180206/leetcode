/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        bool isneg = num < 0;
        num = abs(num);

        string ans;
        while (num > 0) {
            ans.push_back(num % 7 + '0');
            num /= 7;
        }

        if  (isneg) ans.push_back('-');
        reverse(ans.begin(), ans.end());

        return ans.empty() ? "0" : ans;
    }
};
// @lc code=end

