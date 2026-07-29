/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> fact(n);
        fact[0] = 1;

        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;

        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        k--;

        string ans;

        for (int i = n; i >= 1; i--)
        {
            int idx = k / fact[i - 1];
            ans += char(nums[idx] + '0');

            nums.erase(nums.begin() + idx);

            k %= fact[i - 1];
        }

        return ans;
    }
};
// @lc code=end
