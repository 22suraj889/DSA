// Minimum multiplication to reach the end

/*
    Intuition:- First thought which strike in our mind to use recursion and then optimize the solution using dp but as there is MOD so  when we take element from array and multiply it and find MOD from it may stuck in infinite loop so we can't apply recursion

    Why Dijkstra ? As MOD is there so the possible nodes can be from 1 to 99999 and we can find minimum steps to reach end from it.
    TC:- O(10^5*n) but this is hypothetical as the number will not be generated from 1 -> 99999 so TC will be lesser than that
    SC:- O(10^5) it will be again lesser than that because of the same above reason
*/

#define MOD 100000
class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        vector<int> steps(100000, 1e9);
        steps[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});
        while (!q.empty())
        {
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();
            for (int i = 0; i < arr.size(); i++)
            {
                int ele = (node * arr[i]) % MOD;
                if (ele == end)
                {
                    return dist + 1;
                }
                if (dist + 1 < steps[ele])
                {
                    steps[ele] = dist + 1;
                    q.push({dist + 1, ele});
                }
            }
        }
        return -1;
    }
};