class Solution {
public:
    int has_path(vector<vector<int>>& grid, int x, int y)
    {
        if (y == grid.size()) return x;
        if ((grid[y][x] == 1 && x + 1 == grid[0].size()) ||
            (grid[y][x] == -1 && x - 1 < 0))
            return -1;
        if ((grid[y][x] == 1 && grid[y][x + 1] == -1) || (grid[y][x] == -1 && grid[y][x - 1] == 1))
            return -1;
        return ((grid[y][x] == 1) ? has_path(grid, x + 1, y + 1) : has_path(grid, x - 1, y + 1));
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;

        for (int x = 0; x < grid[0].size(); ++x)
            ans.push_back(has_path(grid, x, 0));
        return ans;
    }
};