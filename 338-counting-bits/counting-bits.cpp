class Solution {
public:
    vector<int> countBits(int n) {
       // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
       // 0 1 1 2 1 2 
       // k = 4
       if (!n) return {0};
       if (n == 1) return {0, 1};
       vector<int> dp(n + 1, 1);
       int k = 2;

       dp[0] = 0;
       dp[1] = dp[2] = 1;
       for (int i = 3; i <= n; ++i) {
            if (i - k == k)
                k = i;
            else
                dp[i] += dp[i - k];
       }
       return dp;
    }
};