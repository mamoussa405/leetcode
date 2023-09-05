class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n, vector<int>(n, -1));
       int nodes = n * n;
       int x = 0, y = 0;
       int num = 1;
       string dir = "right";

       while (nodes--)
       {
            ans[y][x] = num++;
            if (dir == "right" && (x + 1 >= n || ans[y][x + 1] != -1))
                dir = "down";
            if (dir == "down" && (y + 1 >= n || ans[y + 1][x] != -1))
                dir = "left";
            if (dir == "left" && (x - 1 < 0 || ans[y][x - 1] != -1))
                dir = "up";
            if (dir == "up" && (y - 1 < 0 || ans[y - 1][x] != -1))
                dir = "right";
            x += (dir == "right");
            x -= (dir == "left");
            y += (dir == "down");
            y -= (dir == "up");
       }
       return ans;
    }
};