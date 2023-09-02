class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> cols(n, vector<int>(n));
        vector<vector<int>> rows(n, vector<int>(n)); 
        int ans = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cols[i][j] = grid[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                rows[i][j] = grid[j][i];
        for (int i = 0; i < n; ++i) 
        {
            for (int k = 0; k < n; ++k)
            {
                int j = 0;
                while (j < n)
                {
                    if (cols[i][j] != rows[k][j])
                        break;
                    ++j;
                }
                ans += j == n;
            }
        }
        return ans;
    }
};