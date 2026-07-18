/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
public:
    int manDist(vector<vector<int>> &points, int p1, int p2)
    {
        return abs(points[p1][0] - points[p2][0]) +
               abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int mstCost = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<bool> vis(points.size(), false);

        while (!pq.empty())
        {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = true;
            mstCost += wt;

            for (int i = 0; i < points.size(); i++)
            {
                if (!vis[i])
                {
                    int edgeweight = manDist(points, i, node);
                    pq.push({edgeweight, i});
                }
            }
        }
        return mstCost;
    }
};
// @lc code=end
