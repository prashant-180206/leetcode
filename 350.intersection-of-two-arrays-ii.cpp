/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m1, m2;
        for (int num : nums1)
            m1[num]++;
        for (int num : nums2)
            m2[num]++;
        vector<int> ans;
        for (auto &p : m1)
        {
            if (m2.count(p.first))
            {
                int count = min(p.second, m2[p.first]);
                for (int i = 0; i < count; i++)
                    ans.push_back(p.first);
            }
        }
        return ans;
    }
};
// @lc code=end
