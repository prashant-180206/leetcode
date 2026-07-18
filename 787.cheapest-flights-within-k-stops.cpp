/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findCheapestPrice(int edge, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> graph(edge);
        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            graph[u].push_back({v, cost});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(edge, INT_MAX);

        dist[src] = 0;
        q.push({src, {0, -1}});

        while (q.size() > 0)
        {
            auto p = q.front();
            int u = p.first;
            int cost = p.second.first;
            int stops = p.second.second;

            q.pop();

            for (auto edge : graph[u])
            {
                int v = edge.first;
                int wt = edge.second;

                if (dist[v] > cost + wt && stops + 1 <= k)
                {
                    dist[v] = cost + wt;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
// @lc code=end
