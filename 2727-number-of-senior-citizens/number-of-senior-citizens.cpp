class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for (string& s : details) {
            int age = stod(s.substr(11, 2));
            ans += (age > 60);
        }
        return ans;
    }
};