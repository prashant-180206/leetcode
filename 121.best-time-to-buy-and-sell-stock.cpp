/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int maxpr = 0;

        for (int i =1 ; i<prices.size();i++){
           int profit = prices[i]- bestBuy;
           maxpr = max(maxpr,profit);
           bestBuy = min(bestBuy, prices[i]);
        }

        return maxpr;
        
    }
};
// @lc code=end

