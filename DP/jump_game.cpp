// leetcode 55 Jump Game based on dp

/* Intuition
    Initial we've to think of brute force approach in which we will see that we have to make all possible jump from
    the current index to the next index, and for that we've to apply recursion as there can be many ways so we cannot do it by loop. So by that we came with the idea of recursion. Also we see that we face problem only when there is 0 in the nums array and if we don't have 0 we'll always reach the end of the array.

    After applying recursion it'll gives us tle and that we can solve using dp
    As only one changing parameter is there in every function call so we need only 1D array for dp

*/

// Recursive approach
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            return true;
        }

        return helper(0, nums);
    }

    bool helper(int index, vector<int> &nums)
    {
        if (index == nums.size() - 1)
        {
            return true;
        }
        if (nums[index] == 0)
        {
            return false;
        }

        for (int i = 1; i <= nums[index]; i++)
        {
            if (helper(index + i, nums))
                return true;
        }
        return false;
    }
};





// Dynamic Programming
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            return true;
        }
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }

    bool helper(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == nums.size() - 1)
        {
            return true;
        }
        if (nums[index] == 0)
        {
            return false;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        int ans = 0;
        for (int i = 1; i <= nums[index]; i++)
        {
            if (helper(index + i, nums, dp))
            {
                ans = 1;
                break;
            }
        }
        dp[index] = ans;
        return ans;
    }
};