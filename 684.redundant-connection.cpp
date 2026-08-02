/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution
{
    vector<int> parent, rank;

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v))
                return edge;

            unite(u, v);
        }

        return {};
    }
};
// @lc code=end