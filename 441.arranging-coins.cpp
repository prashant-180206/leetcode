/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution
{
    typedef long long ll;
public:
    int arrangeCoins(int n)
    {
        ll low = 1;
        ll high = n;

        while (low <= high)
        {
            ll mid = low + (high - low) / 2;

            ll coins = mid * (mid + 1) / 2;

            if (coins == n)
                return mid;
            else if (coins < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

// @lc code=end
