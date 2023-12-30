class Solution {
    public:
        void solve(int n, bool& ans, bool turn, map<int, bool>& dp) {
            if (n == 1 || n == 0) {
                ans = ans || !turn;
                return;
            }
            bool found_number = false;
            for  (int i = 1; i < n; ++i) {
                if (n % i == 0) {
                    if (dp.count(i))
                        found_number = found_number || dp[i];
                    else {
                        solve(n - i, ans, !turn, dp);
                        found_number = true;
                    }
                }
            }
            ans = ans || (!turn && !found_number);
            dp[n] = ans;
        }
        bool divisorGame(int n) {
            bool ans = false;
            map<int, bool> dp;
            solve(n, ans, 1, dp);        
            return ans;
        }
};