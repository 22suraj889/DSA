// leetcode 802


// by dfs with the help of visited array and pathVisit array
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // dfs + pathVisited
        int v = graph.size();
        vector<int>visit(v, 0);
        vector<int>pathVisit(v, 0);
        vector<int>check(v, 0);
        for(int i=0; i<v; i++){
            if(!visit[i]){
                dfs(graph, i, visit, pathVisit, check);
            }
        }

        vector<int>ans;
        for(int i=0; i<v; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& visit, vector<int>& pathVisit, vector<int>& check){
        visit[node] = 1;
        pathVisit[node] = 1;
        check[node] = 0;
        for(auto it : graph[node]){

            if(!visit[it]){
                if(dfs(graph, it, visit, pathVisit, check) == true){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisit[it]){
                check[node] = 0;
                return true;
            }
        }

        pathVisit[node] = 0;
        check[node] = 1;
        return false;
    }
};