/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> s;
        for (int c : candyType)
            s.insert(c);

        int n = candyType.size() / 2;
        return min(n, (int)s.size());
    }
};
// @lc code=end
