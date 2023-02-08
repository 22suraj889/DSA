// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

/*
    Intuition :- as we've to reach from every city other city and check from which city we can reach to other city in threshold distance and we have to find smallest number of cities which can be reached by the threshold distance

    TC :- O(N^3) and SC :- O(N*N)
*/

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> d(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; i++)
        {
            d[i][i] = 0;
        }
        for (auto it : edges)
        {
            d[it[0]][it[1]] = it[2];
            d[it[1]][it[0]] = it[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j || i == k || j == k)
                        continue;

                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        int ans = 0, minAns = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (d[i][j] <= distanceThreshold)
                    ++count;
            }

            if (minAns >= count)
            {
                ans = i;
                minAns = count;
            }
        }
        return ans;
    }
};
