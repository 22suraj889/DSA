// leetcode 1834 Single-Threaded CPU

/*
    This is SJF implementation question from OS and good question which implement priority queue

    Intuition priority queue
    1. At a particular time let say t when a certain task is finished, all the tasks which arrived earlier than t and on time t will be in the queue. So to put tasks in the queue we need to sort the tasks based on enqueueTime and then we will put those tasks in the queue which arrived earlier than t or on time t.
    2. As there can be multiple tasks in the queue waiting for processing at a particular time and which task will be processed first will be based on tasks processing time. Tasks in the queue which is having less processing
    time will be processed first. So for tasks based on processing time we will store in min-heap and top element of the min-heap will give us the task with minimum processing time.
    3. Also check some cases in which we've to write some if-statements
*/

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        using pp = pair<int, pair<int, int>>;
        int n = tasks.size();
        vector<pp> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({tasks[i][0], {tasks[i][1], i}});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        ans.push_back(arr[0].second.second);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        int i = 1;
        int count = arr[0].first + arr[0].second.first;
        while (i < n || !pq.empty())
        {
            while ((i < n && count >= arr[i].first) || pq.empty())
            {
                pq.push({arr[i].second.first, {arr[i].second.second, arr[i].first}});
                ++i;
            }
            ans.push_back(pq.top().second.first);
            if (count < pq.top().second.second)
            {
                count = pq.top().first + pq.top().second.second;
            }
            else if (i < n)
            {
                count += pq.top().first;
            }
            pq.pop();
        }
        return ans;
    }
};