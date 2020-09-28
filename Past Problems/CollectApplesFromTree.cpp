// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

// Example 1:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
// Output: 8
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.

#include <bits/stdc++.h>
#include "./headers/data_structures/BinaryTree.h"

using namespace std;

int main()
{
}

class Solution
{
    vector<vector<int>> adj;
    vector<int> parent;
    vector<bool> needed;
    int ans;

    bool dfs(int id, vector<bool> &hasApple)
    {
        int s = 0;
        bool valid = hasApple[id];
        for (auto p : adj[id])
        {
            if (parent[p] == -1)
            {
                parent[p] = id;
                bool v = dfs(p, hasApple);
                valid = valid || v;
            }
        }
        needed[id] = valid;
        return valid;
    }

    void calc(int id)
    {
        for (auto p : adj[id])
        {
            if ((parent[p] == id) && (needed[p]))
            {
                ans += 2;
                calc(p);
            }
        }
    }

public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        adj.clear();
        adj.resize(n);
        for (auto p : edges)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        parent.assign(n, -1);
        parent[0] = -2;
        needed.assign(n, false);
        dfs(0, hasApple);

        ans = 0;
        calc(0);
        return ans;
    }
};