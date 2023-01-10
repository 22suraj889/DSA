// gfg Shortest Distance in a Binary Maze

/*
    DFS approach
    TC- O(4^m*n) as there are 4 calls   SC- O(m*n)
*/

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        if (dfs(grid, source.first, source.second, destination) - 1 == 1e7)
        {
            return -1;
        }
        return dfs(grid, source.first, source.second, destination) - 1;
    }
    int dfs(vector<vector<int>> &grid, int row, int col, pair<int, int> &end)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || grid[row][col] == -1)
        {
            return 1e7;
        }
        if (grid[row][col] == 1 && row == end.first && col == end.second)
        {
            return 1;
        }
        grid[row][col] = -1;
        int up = dfs(grid, row - 1, col, end);
        int down = dfs(grid, row + 1, col, end);
        int left = dfs(grid, row, col - 1, end);
        int right = dfs(grid, row, col + 1, end);
        grid[row][col] = 1;
        return 1 + min(min(up, down), min(left, right));
    }
};





/*
    Using BFS Dijkstra algorithm
    In this priority queue not taken because as the distance moved in each step is 1 so distance will be stored in increasing order

    TC- O(m*n) and SC- O(m*n)
*/

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // code here
        if (dfs(grid, source.first, source.second, destination) - 1 == 1e7)
        {
            return -1;
        }
        return dfs(grid, source.first, source.second, destination) - 1;
    }
    int dfs(vector<vector<int>> &grid, int row, int col, pair<int, int> &end)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || grid[row][col] == -1)
        {
            return 1e7;
        }
        if (grid[row][col] == 1 && row == end.first && col == end.second)
        {
            return 1;
        }
        grid[row][col] = -1;
        int up = dfs(grid, row - 1, col, end);
        int down = dfs(grid, row + 1, col, end);
        int left = dfs(grid, row, col - 1, end);
        int right = dfs(grid, row, col + 1, end);
        grid[row][col] = 1;
        return 1 + min(min(up, down), min(left, right));
    }
};