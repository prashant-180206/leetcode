/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
                for (int j = 2; j * i < n; j++)
                {
                    isPrime[i * j] = false;
                }
            }
        }
        return count;
    }
};
// @lc code=end
