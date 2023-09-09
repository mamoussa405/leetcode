class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       int m = mat.size(); 
       int n = mat[0].size();
       int node = m * n;
       bool up = 1;
       int x = 0, y = 0;
       vector<int> ans(node);
       int i = 0;

       while (node)
       {
            ans[i] = mat[y][x]; ++i;
            if (--node == 0) break;
            if (up && y - 1 >= 0 && x + 1 < n)
            {
               y -= 1;
               x += 1; 
            }
            else if (!up && x - 1 >= 0 && y + 1 < m)
            {
                x -= 1;
                y += 1;
            } 
            else
            {
                if (up)
                    (x + 1 < n) ? ++x : ++y, up = 0;
                else
                    (y + 1 < m) ? ++y : ++x, up = 1;
            }
       }
       return ans;
    }
};