// leetcode 802

// by dfs with the help of visited array and pathVisit array
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        // dfs + pathVisited
        int v = graph.size();
        vector<int> visit(v, 0);
        vector<int> pathVisit(v, 0);
        vector<int> check(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!visit[i])
            {
                dfs(graph, i, visit, pathVisit, check);
            }
        }

        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (check[i] == 1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>> &graph, int node, vector<int> &visit, vector<int> &pathVisit, vector<int> &check)
    {
        visit[node] = 1;
        pathVisit[node] = 1;
        check[node] = 0;
        for (auto it : graph[node])
        {

            if (!visit[it])
            {
                if (dfs(graph, it, visit, pathVisit, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVisit[it])
            {
                check[node] = 0;
                return true;
            }
        }

        pathVisit[node] = 0;
        check[node] = 1;
        return false;
    }
};




// by bfs kahn's algorithm with help of in-degree array
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        // bfs kahn's algo
        int n = graph.size();
        vector<int> adj[n];

        // first reversing all the edges of the graph
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }

        // creating in-degree array for all node
        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                degree[it]++;
            }
        }

        // pushing all the node whose in-degree is 0
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                q.push(i);
            }
        }

        // applying bfs
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                degree[it]--;
                if (degree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};