// leetcode 2244 Minimum Rounds to Complete All Tasks

/*
    brute force approach using visited array so that we don't start counting from the same element which we've counted earlier
    TC- O(n^2) and SC- O(n)
*/

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        // brute force approach using visited array so that we don't start counting from the same element which we've counted earlier

        int n = tasks.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int count = 0;
                for (int j = i; j < n; j++)
                {
                    if (tasks[i] == tasks[j])
                    {
                        ++count;
                        visited[j] = 1;
                    }
                }

                if (count == 1)
                {
                    return -1;
                }
                else if (count % 3 == 0)
                {
                    ans += count / 3;
                }
                else if (count % 3 == 1)
                {
                    ans += (((count - 4) / 3) + 2);
                }
                else if (count % 3 == 2)
                {
                    ans += ((count / 3) + 1);
                }
            }
        }
        return ans;
    }
};





/*
    Sorting so that we don't have to count occurrences of a number by iterating over array again and again
    TC- O(nlogn) SC- O(1)
*/

class Solution {
public:
    int helper(int count){
        if(count == 1)
            return -1;
        else if(count%3 == 0)
            return count/3;
        else if(count%3 == 1)
            return (((count-4)/3) + 2);
        else if(count%3 == 2)
            return ((count/3) + 1);
        
        return 0;
    }
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        if(n == 1 || tasks[0] != tasks[1] || tasks[n-1] != tasks[n-2]){
            return -1;
        }
        int count = 1, ans = 0;
        for(int i=0; i<n; i++){
            if(i != 0 && tasks[i] == tasks[i-1]){
                ++count;
                if(i == n-1){
                    int x = helper(count);
                    if(x == -1)
                        return -1;
                     ans += x;                  
                }
            }
            else if(i != 0 && tasks[i] != tasks[i-1]){
                int x = helper(count);
                if(x == -1)
                    return -1;
                ans += x;
                count = 1;
            }
        }
        return ans;
    }
};





/*
    Use map to store the count of numbers
    TC- O(n) and SC- O(n)
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int it : tasks){
            mp[it]++;
        }

        int ans = 0;
        for(auto it : mp){
            int count = it.second;
            if(count == 1){
                return -1;
            }
            else if(count%3 == 0){
                ans += count/3;
            }
            else if(count%3 == 1){
                ans += (((count-4)/3) + 2);
            }
            else if(count%3 == 2){
                ans += ((count/3) + 1);
            }
        }
        return ans;
    }
};