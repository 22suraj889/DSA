// gfg practice

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // dfs code for cycle detection + pathVisit
        vector<int>visited(v, 0), pathVisited(v, 0);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int n, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited){
        visited[n] = 1;
        pathVisited[n] = 1;
        for(auto  it : adj[n]){
            if(!visited[it] && dfs(it, adj, visited, pathVisited) == true){
                return true;
            }
            if(pathVisited[it] == 1){
                return true;
            }
        }
        pathVisited[n] = 0;
        return false;
    }
};
