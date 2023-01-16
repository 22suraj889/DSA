// leetcode 57 Insert Interval

/*
    Intuition :- merge interval
    TC :- O(n*log(n)) and SC :- O(1)
    Insert the newInterval into interval and sort them
*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> v = intervals;
        v.push_back(newInterval);
        sort(v.begin(), v.end());
        int n = v.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            a.push_back(v[i][0]);
            int maxVal = v[i][1];
            int j = i + 1;
            for (; j < n; j++)
            {
                if (maxVal < v[j][0])
                {
                    break;
                }
                if (maxVal >= v[j][0] && maxVal <= v[j][1])
                {
                    maxVal = v[j][1];
                }
            }
            i = j - 1;
            a.push_back(maxVal);
            ans.push_back(a);
        }
        return ans;
    }
};







/*
    We don't need to sort the array, as interval array is already sorted by first value so just create a new one with keeping newInterval in right place
    TC :- O(n) and SC :- O(1)
*/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> v;
        int n = intervals.size();
        int i = 0;
        while (i < n && newInterval[0] >= intervals[i][0])
        {
            v.push_back(intervals[i]);
            ++i;
        }
        v.push_back(newInterval);
        while (i < n)
        {
            v.push_back(intervals[i]);
            ++i;
        }
        n++;

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            a.push_back(v[i][0]);
            int maxVal = v[i][1];
            int j = i + 1;
            for (; j < n; j++)
            {
                if (maxVal < v[j][0])
                {
                    break;
                }
                if (maxVal >= v[j][0] && maxVal <= v[j][1])
                {
                    maxVal = v[j][1];
                }
            }
            i = j - 1;
            a.push_back(maxVal);
            ans.push_back(a);
        }
        return ans;
    }
};