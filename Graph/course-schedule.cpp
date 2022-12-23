// leetcode Q. 207

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>graph(n, vector<int>(n, 0));
        for(int i=0; i<pre.size(); i++){
            graph[pre[i][1]][pre[i][0]] = 1; 
        }

        // if there is any undirected edge
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == 1 && graph[j][i] == 1){
                    return false;
                }
            }
        }

        vector<int>degree(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == 1){
                    degree[j]++;
                }
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<n; i++){
                if(graph[node][i] == 1){
                    degree[i]--;
                    if(degree[i] == 0){
                        q.push(i);
                    }
                }
            }
        }

        for(int i=0; i<n; i++){
            if(degree[i] != 0){
                return false;
            }
        }

        return true;
    }
};