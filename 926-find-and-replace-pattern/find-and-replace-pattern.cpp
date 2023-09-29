class Solution {
public:
    bool mapped(map<char, char>& m, char s, char p)
    {
        for (auto& it : m)
            if (it.second == s && it.first != p)
                return (1);
        return (0);
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (string& s : words)    
        {
            map<char, char> m;
            bool take = 1;
            for (int i = 0; i < pattern.size(); ++i)
            {
                if (m.count(pattern[i]) && m[pattern[i]] != s[i]
                || mapped(m, s[i], pattern[i]))
                {
                    take = 0;
                    break;
                }
                m[pattern[i]] = s[i];
            }
            if (take)
                ans.push_back(s);
        }
        return ans;
    }
};