/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalcost = 0;

        int start = 0, currentgas = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalcost += cost[i];
            currentgas = currentgas + gas[i] - cost[i];
            if (currentgas < 0)
            {
                start = i + 1;
                currentgas = 0;
            }
        }

        return totalcost <= totalGas ? start : -1;
    }
};
// @lc code=end
