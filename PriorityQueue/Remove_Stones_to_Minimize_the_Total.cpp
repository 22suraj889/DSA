// leetcode 1962 Remove Stones to Minimize the Total

/* Intuition Brute force find maximum all k time from array after modification of the array
    TC O(n^2) for n = k = 1e5
*/
class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int n = piles.size();
        while (k)
        {
            int index = 0, maxVal = piles[0];
            for (int i = 1; i < n; i++)
            {
                if (maxVal < piles[i])
                {
                    maxVal = piles[i];
                    index = i;
                }
            }
            piles[index] -= piles[index] / 2;
            --k;
        }

        int count = 0;
        for (int it : piles)
        {
            count += it;
        }
        return count;
    }
};





/* If we use priority queue we no need to find maximum all time as in priority queue top element will always be the maximum one
    TC- O(n*log(n)) and SC- O(n) for priority queue
*/
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(), piles.end());
        for(int i=0; i<k; i++){
            int top = pq.top();
            pq.pop();
            top -= top/2;
            pq.push(top);
        }
        int count = 0;
        while(!pq.empty()){
            count += pq.top();
            pq.pop();
        }
        return count;
    }
};