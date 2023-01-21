// leetcode 93. Restore IP Addresses

/*
    Approach :- backtracking
    Intuition :- We can generate all the addresses and check for the correct one
    after generating a address check if the address have exactly 4 integer separated by dot then only we'll take it
    TC :- 3^4 as there is 3 recursive call in every level
    SC :- as maximum depth of tree is 4 O(1);
*/

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans, v;
        helper(s, ans, 0, v);
        return ans;
    }
    void helper(string &s, vector<string> &ans, int i, vector<string> v)
    {
        if (v.size() > 4 || (i >= s.length() && v.size() < 4))
        {
            return;
        }

        if (i == s.length() && v.size() == 4)
        {
            string str = "";
            for (int i = 0; i < 4; i++)
            {
                int x = stoi(v[i]);
                int size = v[i].length();
                if ((size == 3 && x >= 100 && x <= 255) || (size == 2 && x >= 10 && x <= 99) || (size == 1 && x >= 0 && x <= 9))
                {
                    str += v[i];
                    str += '.';
                }
                else
                {
                    return;
                }
            }
            str.pop_back();
            ans.push_back(str);
            return;
        }

        string temp = "";
        for (int j = i; j < i + 3; j++)
        {
            if (j < s.length())
            {
                temp += s[j];
                v.push_back(temp);
                helper(s, ans, j + 1, v);
                v.pop_back();
            }
        }
    }
};