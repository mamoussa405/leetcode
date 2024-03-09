class Solution {
public:
    vector<string>  hash = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string>  ans;

    void    dfs( string digits, string curr, int __curr )
    {
        if ( __curr == curr.size() )
        {
            ans.push_back(curr);
            return ;
        }

        for ( int i=0; i<hash[digits[__curr] - '0'].length(); i++ )
        {
            curr[__curr] = hash[digits[__curr] - '0'][i];
            dfs( digits, curr, __curr + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if ( digits.empty()) return (ans);
        dfs(digits, string(digits.size(), ' '), 0);
        return ( ans );
    }
};