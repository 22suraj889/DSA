// leetcode 2279 Maximum Bags With Full Capacity of Rocks

// sorting TC- O(n*log(n)) SC- O(n) for vector v

class Solution
{
public:
    int maximumBags(vector<int> &cap, vector<int> &rocks, int addRocks)
    {
        int n = cap.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(cap[i] - rocks[i]);
        }

        sort(v.begin(), v.end());
        int i = 0;
        while (addRocks != 0 && addRocks >= v[i] && i < n)
        {
            if (v[i] != 0)
            {
                addRocks -= v[i];
                v[i] = 0;
            }
            ++i;
        }

        int count = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == 0)
                ++count;
        }
        return count;
    }
};





// using map which reduces time complexity to O(N) and SC is O(N)
class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int addRocks) {
        // TC O(n) and SC O(n)
        int n = cap.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            int val = cap[i] - rocks[i];
            mp[val]++;
        }

        int count = 0;
        for(auto it : mp){
            if(it.first == 0){
                count += it.second;
            }
            else if(addRocks >= it.first){
                int num = addRocks/it.first;
                if(num >= it.second){
                    count += it.second;
                    addRocks -= (it.first*it.second);
                }
                else{
                    count += num;
                    addRocks -= (num*it.first);
                    break;
                }
            }
            else if(addRocks < it.first){
                break;
            }
        }

        return count;
    }
};