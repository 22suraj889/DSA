// leetcode 2389

// Solution-1 brute force  TC- O(n*m) ===> n = nums.size() and m = q.size() and according to question 1 < n, m <= 1000
// so in worst case TC- O(n^2)
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &q)
    {
        int n = nums.size();
        // this will take O(n*logn)
        sort(nums.begin(), nums.end());
        vector<int> ans;

        // this will take O(n*n) if nums.size() == q.size() == n
        for (int i = 0; i < q.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += nums[j];
                if (sum > q[i])
                {
                    ans.push_back(j);
                    break;
                }
            }
            if (sum <= q[i])
            {
                ans.push_back(n);
            }
        }
        return ans;
    }
};





// solution-2 binary search + prefix array
// this will take O(n*log(n)) time for sorting array + O(n) for creating prefix array + O(n*log(n)) for iterating
// over query array and then finding maximum subsequence size sum by binary search which take O(log(n)) time
// so overall time is O(n*log(n)) + O(n) + O(n*log(n)) ==> O(n*log(n))
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &q)
    {
        // using prefix sum and binary search which takes O(n*logn)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            cout << prefix[i] << endl;
        }

        vector<int> ans;
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] < prefix[n - 1])
            {
                int start = 0, end = n - 1;
                int size = 0;
                while (start <= end)
                {
                    int mid = (start + end) / 2;
                    if (prefix[mid] == q[i])
                    {
                        size = mid + 1;
                        break;
                    }
                    else if (prefix[mid] < q[i])
                    {
                        size = mid + 1;
                        start = mid + 1;
                    }
                    else
                    {
                        end = mid - 1;
                    }
                }
                ans.push_back(size);
            }
            else
            {
                ans.push_back(n);
            }
        }
        return ans;
    }
};