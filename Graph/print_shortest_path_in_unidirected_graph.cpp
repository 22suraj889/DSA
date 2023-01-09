// gfg Shortest Path in Weighted undirected graph

/*
    First we can solve it using dfs + pathVisited array + backtracking
    TC- O(V^2) and SC- O(V) for stack + O(V) for pathVisited array
*/

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> ans, pathVisit(n + 1, 0), v;
        int shortDis = 1e9;
        dfs(1, pathVisit, v, ans, shortDis, 0, adj);
        if (shortDis == 1e9)
        {
            ans.push_back(-1);
        }
        return ans;
    }
    void dfs(int node, vector<int> &pathVisit, vector<int> v, vector<int> &ans, int &shortDis, int dis, vector<pair<int, int>> adj[])
    {
        v.push_back(node);
        if (node == pathVisit.size() - 1 && shortDis > dis)
        {
            ans = v;
            shortDis = dis;
            return;
        }
        pathVisit[node] = 1;
        for (auto it : adj[node])
        {
            if (!pathVisit[it.first])
            {
                dfs(it.first, pathVisit, v, ans, shortDis, dis + it.second, adj);
            }
        }
        pathVisit[node] = 0;
        v.pop_back();
    }
};





/*
    Approach:- Dijkstra algorithm. Also keep the path which you are visiting to get shortest distances from the source to all nodes in priority queue with node and distance
    TC- O(E*logV)  SC- O(V) for priority queue but as we are also inserting path as well so the it should be complex
*/

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> shortDist(n + 1, 1e9);
        shortDist[1] = 0;
        priority_queue<pair<int, pair<int, vector<int>>>, vector<pair<int, pair<int, vector<int>>>>, greater<pair<int, pair<int, vector<int>>>>> pq;
        vector<int> v;
        v.push_back(1);
        pq.push({0, {1, v}});

        int ansDist = 1e9;
        vector<int> ans;

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second.first;
            vector<int> path = pq.top().second.second;
            pq.pop();
            if (node == n && ansDist > dist)
            {
                ansDist = dist;
                ans = path;
            }

            for (auto it : adj[node])
            {
                if (shortDist[it.first] > dist + it.second)
                {
                    shortDist[it.first] = dist + it.second;
                    path.push_back(it.first);
                    pq.push({dist + it.second, {it.first, path}});
                    path.pop_back();
                }
            }
        }

        if (ansDist == 1e9)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};





/*
    Dijkstra algorithm, BFS + keep track of the path from we found the shortest distance from source to all nodes using another array and backtrack that array from destination index to get shortest path
*/

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> shortDist(n + 1, 1e9);
        shortDist[1] = 0;
        vector<int> path(n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int pathDist = dist + it.second;
                if (shortDist[it.first] > pathDist)
                {
                    shortDist[it.first] = pathDist;
                    path[it.first] = node;
                    pq.push({pathDist, it.first});
                }
            }
        }

        vector<int> ans;
        if (path[n] == -1)
        {
            ans.push_back(-1);
        }
        else
        {
            int i = n;
            while (path[i] != -1)
            {
                ans.push_back(i);
                i = path[i];
            }
            ans.push_back(1);
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};