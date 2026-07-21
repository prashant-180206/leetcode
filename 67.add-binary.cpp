/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        string ans;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            sum += carry;
            ans += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
