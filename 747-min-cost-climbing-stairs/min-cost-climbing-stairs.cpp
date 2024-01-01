class Solution {
public:

    int solve(vector<int>& cost, vector<int>& dp, int n) {
        if (n == cost.size()) return 0;
        if (n == cost.size() - 1) return cost[n];
        if (dp[n] != -1) return dp[n];
        int ans = cost[n];

        ans += min(solve(cost, dp, n + 1), solve(cost, dp, n + 2));
        dp[n] = ans;
        return  ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost, dp, 0), solve(cost, dp, 1));
    }
};