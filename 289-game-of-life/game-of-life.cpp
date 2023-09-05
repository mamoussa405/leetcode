class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8][2] = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
            {1, -1},
            {1, 1},
            {-1, 1},
            {-1, -1}
        };
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> tmp_board(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                tmp_board[i][j] = board[i][j];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int live_nei = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int nx = j + dx[k][0];
                    int ny = i + dx[k][1];
                    if (nx < n && nx >= 0 && ny < m && ny >= 0)
                        live_nei += tmp_board[ny][nx];
                }
                if (board[i][j])
                {
                    if (live_nei < 2) 
                        board[i][j] = 0;
                    else if (live_nei > 3)
                        board[i][j] = 0;
                } else if (live_nei == 3)
                    board[i][j] = 1;
            }
        } 
    }
};