// leetcode 472 concatenated word

/*
    Intuition :- normal backtracking
    TC > O(2^n)
*/
class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        unordered_map<string, bool> mp;
        int maxLen = 0;
        for (string s : words)
        {
            mp[s] = true;
            int len = s.length();
            maxLen = max(maxLen, len);
        }
        vector<string> ans;
        helper(words, "", 0, 0, mp, ans, maxLen);
        return ans;
    }
    void helper(vector<string> &words, string word, int wordCount, int i, unordered_map<string, bool> &mp, vector<string> &ans, int &maxLen)
    {
        if (i == words.size())
        {
            return;
        }

        // taken ith string as a part of word
        if (word.length() < maxLen)
        {
            string w = word;
            word += words[i];
            wordCount++;
            if (mp.count(word) == 1 && wordCount > 1)
            {
                ans.push_back(word);
            }
            helper(words, word, wordCount, 0, mp, ans, maxLen);
            word = w;
            wordCount--;
        }
        // not taken ith string as a part of word
        helper(words, word, wordCount, i + 1, mp, ans, maxLen);
    }
};