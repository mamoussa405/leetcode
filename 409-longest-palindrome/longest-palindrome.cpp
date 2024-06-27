class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> f;
        int ans = 0;
        bool is_odd = 0;

        for (char& c : s)
            ++f[c];
        for (auto& n : f) {
            ans += n.second - (n.second  % 2);
            is_odd = is_odd || (n.second % 2 != 0);
        } 
        ans += is_odd;
        return f.size() == 1 ? s.size() : ans;
    }
};