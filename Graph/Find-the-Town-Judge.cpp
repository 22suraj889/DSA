// leetcode 997 Find the Town Judge

/*
    Find how many peoples trust on ith person and how many ith person trust on other peoples
    TC:- O(N*lengthOf(trust)) and SC:- O(1)
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        for (int i = 1; i <= n; i++)
        {
            int inDegree = 0;
            int outDegree = 0;
            for (auto it : trust)
            {
                if (it[0] == i)
                    ++outDegree;
                if (it[1] == i)
                    ++inDegree;
            }
            if (inDegree == n - 1 && outDegree == 0)
            {
                return i;
            }
        }
        return -1;
    }
};




/*
    just use inDegree and outDegree array.We will be filling inDegree and outDegree, inDegree will show number of people having trust on ith person and outDegree will show number of people ith person trust on and if for ith person inDegree is n-1 and outDegree is 0 that means that ith person is judge
    TC:- O(lengthOf(trust)) and SC:- O(n)
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);

        // we will be filling inDegree and outDegree, inDegree will show number of people having trust on ith person and outDegree will show number of people ith person trust on
        for (auto it : trust)
        {
            inDegree[it[1]]++;
            outDegree[it[0]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};