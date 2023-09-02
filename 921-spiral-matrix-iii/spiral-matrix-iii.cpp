class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<vector<bool>> vis(rows, vector<bool>(cols, 0));
        int step = 1;
        int movedTimes = 0;
        string dir = "right";
        int n = rows * cols;

        ans.push_back({rStart, cStart});
        vis[rStart][cStart] = 1;
        --n;
        while (n > 0)
        {
            if (movedTimes == 2)
                ++step, movedTimes = 0;
            if (dir == "right")
            {
                if (rStart < rows && rStart >= 0)
                {
                    for (int k = 1; k <= step; ++k)
                    {
                        ++cStart;
                        if ((cStart >= cols || cStart < 0) || vis[rStart][cStart]) continue;
                        ans.push_back({rStart, cStart});
                        vis[rStart][cStart] = 1;
                        --n;
                        if (!n) break;
                    }
                } else cStart += step;
                dir = "down";
            }
            else if (dir == "down")
            {
                if (cStart < cols && cStart >= 0)
                {
                    for (int k = 1; k <= step; ++k)
                    {
                        ++rStart;
                        if ((rStart >= rows || rStart < 0) || vis[rStart][cStart]) continue;
                        ans.push_back({rStart, cStart});
                        vis[rStart][cStart] = 1;
                        --n;
                        if (!n) break;
                    }
                } else rStart += step;
                dir = "left";
            }
            else if (dir == "left")
            {
                if (rStart < rows && rStart >= 0)
                {
                    for (int k = 1; k <= step; ++k)
                    {
                        --cStart;
                        if ((cStart >= cols || cStart < 0) || vis[rStart][cStart]) continue;
                        ans.push_back({rStart, cStart});
                        vis[rStart][cStart] = 1;
                        --n;
                        if (!n) break;
                    }
                } else cStart -= step;
                dir = "up";
            }
            else
            {
                if (cStart < cols && cStart >= 0)
                {
                    for (int k = 1; k <= step; ++k)                    
                    {
                        --rStart;
                        if ((rStart >= rows || rStart < 0) || vis[rStart][cStart]) continue;
                        ans.push_back({rStart, cStart});
                        vis[rStart][cStart] = 1;
                        --n;
                        if (!n) break;
                    }
                } else rStart -= step;
                dir = "right";
            }
            ++movedTimes;
        }
        return ans;
    }
};