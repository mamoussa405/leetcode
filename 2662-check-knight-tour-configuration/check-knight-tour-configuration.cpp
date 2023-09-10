class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int dx[8][2] = {
            {1, -2}, {2, -1},
            {2, 1}, {1, 2},
            {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}
        };
        int n = grid.size();
        int nodes = n * n;
        int curr = grid[0][0];
        int x = 0, y = 0;

        if (curr) return 0;
        while (--nodes)
        {
            bool isValid = 0;
            for (int i = 0; i < 8; ++i)
            {
                int nx = x + dx[i][0];
                int ny = y + dx[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (grid[ny][nx] == curr + 1)
                    {
                        isValid = 1;
                        ++curr;
                        x = nx;
                        y = ny;
                        break;
                    }
                }
            }
            if (!isValid)
                return 0;
        }
        return 1;
    }
};