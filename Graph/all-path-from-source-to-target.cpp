// leetcode 797

/*
    Intuition DFS
    Simple Intuition is to apply dfs and to push all the nodes in the path in a vector and finally when we reach
    the target node we push path vector to our answer vector
*/

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(0, ans, v, graph);
        return ans;
    }
    void dfs(int node, vector<vector<int>> &ans, vector<int> v, vector<vector<int>> &graph)
    {
        v.push_back(node);
        if (node == graph.size() - 1)
        {
            ans.push_back(v);
            return;
        }

        for (auto it : graph[node])
        {
            dfs(it, ans, v, graph);
        }
    }
};