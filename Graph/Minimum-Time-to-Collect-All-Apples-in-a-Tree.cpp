// leetcode 1443  Minimum Time to Collect All Apples in a Tree

/*
    Approach DFS
    Intuition :- for the left tree check if there is apple node than only track time to reach from root to that apple node and if there is no apple node then time will be same as usual. Do the same for the right tree.

    TC- O(3*n) as dfs will be visiting all the node ones only and for each node for loop will run for number of edges connected to that node so here as at most there are 3 edges only so 3*n.
    SC- O(logn) height of the tree 
*/

class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<int> adj[n];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        int time = 0;
        int x = dfs(0, 0, time, adj, visited, hasApple);
        return time * 2;
    }
    int dfs(int node, int count, int &time, vector<int> adj[], vector<int> &visited, vector<bool> &hasApple)
    {
        visited[node] = 1;

        int ans = 0;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                int cntApple = 0;
                time++;
                if (hasApple[it])
                {
                    cntApple = 1 + dfs(it, count + 1, time, adj, visited, hasApple);
                }
                else
                {
                    cntApple = dfs(it, count + 1, time, adj, visited, hasApple);
                }

                if (cntApple == 0)
                {
                    time = count;
                }
                else
                {
                    count = time;
                }
                ans += cntApple;
            }
        }
        return ans;
    }
};