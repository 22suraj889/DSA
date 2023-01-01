// leetcode 290 Word Pattern

/*
    TC- O(n^2) where n is the length of string pat and SC- O(N)
    Intuition
    Brute force approach to check if a letter in the string pattern appears again then corresponding to that char index the word appearing in the array formed from string s should be equal and if is is not then return false
*/
class Solution
{
public:
    bool wordPattern(string pat, string s)
    {
        int n = pat.length();
        vector<string> str;
        string word;
        stringstream iss(s);
        while (iss >> word)
        {
            str.push_back(word);
        }

        // if number of alphabets in pattern and number of words in s is different then it'll not follow same pattern
        if (n != str.size())
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            string temp = str[i];
            for (int j = i + 1; j < n; j++)
            {
                if (pat[i] == pat[j])
                {
                    if (temp != str[j])
                    {
                        return false;
                    }
                }
                else
                {
                    if (temp == str[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};




/*
    Intuition
    Keep two map one is char, string and other is string, char. Now we'll check if the char we are currently in string pattern is already present in the first map and if it then we check if corresponding to that index, word in the vector is not equal word present corresponding to the char in the map then we will return false.
    If the char is not present in the first map then we may think of putting it in the map but there is a problem what if the word you are trying to set with the char in the map is already set with other char in the map. So for that we've created two map so if the char is not present in the first map then instead of just putting it in the map we will check the word which we are trying to set with current index char is present in the second map or not. In second map we set string to char so if that word is already set to some char then we will
    return false otherwise we will set that word with char
*/

class Solution
{
public:
    bool wordPattern(string pat, string s)
    {
        int n = pat.length();
        vector<string> str;
        string word;
        stringstream iss(s);
        while (iss >> word)
        {
            str.push_back(word);
        }

        if (n != str.size())
        {
            return false;
        }
        unordered_map<char, string> mp;
        unordered_map<string, char> m;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(pat[i]) == 0)
            {
                if (m.count(str[i]) == 1)
                {
                    return false;
                }
                mp[pat[i]] = str[i];
                m[str[i]] = pat[i];
            }
            else
            {
                if (mp[pat[i]] != str[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};