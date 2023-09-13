class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        int m = accounts.size();
        int n = accounts[0].size();

        for (int r = 0; r < m; ++r) 
        {
            int sum = 0;
            for (int c = 0; c < n; ++c) 
                sum += accounts[r][c];
            ans = max(ans, sum);
        }
        return ans;
    }
};