// gfg Shortest Path in Dijkstra algorithm

/*
    Using priority queue + distance array and applying bfs
    we will adjacent nodes in the priority queue only when distance to that node we found is less than distance already calculated.
    why priority queue and not queue? When we take queue it will explore all the path and when we use priority queue we will greedily find the shortest path for reaching all the nodes.
    TC- E*logV
*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // using priority queue
        vector<int> ans(v, 1e7);
        ans[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (ans[adjNode] > edgeWeight + dist)
                {
                    pq.push({edgeWeight + dist, adjNode});
                    ans[adjNode] = edgeWeight + dist;
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            if (ans[i] == 1e7)
                ans[i] = -1;
        }

        return ans;
    }
};






/*
    set + distance array using bfs
    why set? In the priority queue what was happening is that when the distance to reach let's say node x is infinite and we found shortest distance to reach to node x from source node we were updating the value of it and putting in the priority queue like {y, x}. Now let's say we again found more shorter distance from the source to reach node x and this time the distance is let's say z, so in this case also as we found distance which is more shorter than already found so we will update the distance array i.e, dist[x] = z and we will put {z, x} in the priority queue. Now here is catch as we putted {z, x} in the priority queue and {y, x} is also in the priority queue. First {z, x} will be taken out as the priority queue is min-heap and by that we will find the shortest distance to all adjacent nodes of x with value z. Now again when we take out top element from priority queue this time it is {y, x} and again we will find the shortest distance to all adjacent nodes of x with value y which will not give any result as shortest distance to all adjacent nodes of x is already found from z which is less than y.
    So in the above statement we see that there is no profit in keeping {y, x} in the priority queue as we found {z, x} and z < y. So once we found that z < y and if y is not infinite then we know this {y, x} is present in the priority queue and it doesn't give any profit from keeping {y, x} in the priority queue. So we remove it from the priority queue but as priority queue doesn't erase the value so for that we used set data structure.
    In set data structure elements will be already sorted in the ascending order and the smallest distance element will be on beginning.
*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // using set
        set<pair<int, int>> s;
        vector<int> dist(v, 1e7);
        dist[src] = 0;
        s.insert({0, src});
        while (!s.empty())
        {
            auto it = *(s.begin());
            int distance = it.first;
            int node = it.second;
            s.erase({distance, node});
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                if (dist[adjNode] > edgeWeight + dist[node])
                {
                    if (dist[adjNode] != 1e7)
                    {
                        s.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = edgeWeight + dist[node];
                    s.insert({dist[adjNode], adjNode});
                }
            }
        }

        for (int i = 0; i < v; i++)
        {
            if (dist[i] == 1e7)
                dist[i] = -1;
        }
        return dist;
    }
};