class Solution {
public:
    bool isSubsequence(string s, string t) {
        int last_pos = 0;

        for (char& c : s) {
            bool found = false;
            for (int i = last_pos; i < t.size(); ++i) {
                if (t[i] == c) {
                    last_pos = i + 1;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};