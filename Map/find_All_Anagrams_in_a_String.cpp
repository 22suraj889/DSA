// leetcode 438. Find All Anagrams in a String

/*
    approach :- first store all the p's characters in map , second the length of the substring in s should be equal to the length of the string p, once the length of the substring we received from s try to iterate through the substring and delete characters from the map once we find that map is empty we store the first character position.
    TC:- O(n^2) and SC:- O(2n)
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> mp1, mp2;
        for (char ch : p)
        {
            mp1[ch]++;
        }
        mp2 = mp1;
        int len = s.length();
        int n = p.length();
        vector<int> ans;
        for (int i = 0; i <= len - n; i++)
        {
            mp2 = mp1;
            for (int j = i; j < i + n; j++)
            {
                if (mp2.count(s[j]) == 1)
                {
                    mp2[s[j]]--;
                    if (mp2[s[j]] == 0)
                    {
                        mp2.erase(s[j]);
                    }
                }
            }
            if (mp2.size() == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};





/*
    Sliding window :- do some calculation when size of window is equal to k and on going to new window do calculation of previous element
    TC:- O(N) and SC:- O(N)
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> mp;
        for (char ch : p)
        {
            mp[ch]++;
        }
        vector<int> ans;
        int i = 0, j = 0, n = s.length(), count = mp.size(), len = p.length();
        while (j < n)
        {
            if (mp.count(s[j]) == 1)
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    --count;
                }
            }

            if (j - i + 1 < len)
            {
                ++j;
            }
            else if (j - i + 1 == len)
            {
                if (count == 0)
                {
                    ans.push_back(i);
                }

                if (mp.count(s[i]) == 1)
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                    {
                        ++count;
                    }
                }
                ++i;
                ++j;
            }
        }
        return ans;
    }
};