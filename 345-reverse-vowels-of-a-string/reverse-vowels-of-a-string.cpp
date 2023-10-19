class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (l < r)
        {
            if (v.count(s[l]) && v.count(s[r]))
            {
                swap(s[l], s[r]);
                ++l;
                --r;
                continue;
            }
            l += (!v.count(s[l]));
            r -= (!v.count(s[r]));
        }
        return s;
    }
};