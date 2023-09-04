class Solution {
    vector<vector<int>> _ans;
public:
    void check(vector<vector<bool>>& board, int x, int y, string dir)
    {
        if (x < 0 || x >= 8 || y < 0 || y >= 8)
            return;
        if (board[y][x] == 1)
        {
            _ans.push_back({y, x});
            return;
        }
        if (dir == "left")
            check(board, x - 1, y, dir);
        else if (dir == "right")
            check(board, x + 1, y, dir);
        else if (dir == "down")
            check(board, x, y + 1, dir);
        else if (dir == "up")
            check(board, x, y - 1, dir);
        else if (dir == "dlu")
            check(board, x - 1, y - 1, dir);
        else if (dir == "dld")
            check(board, x - 1, y + 1, dir);
        else if (dir == "dru")
            check(board, x + 1, y - 1, dir);
        else
            check(board, x + 1, y + 1, dir);
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> board(8, vector<bool>(8, 0));

        for (int i = 0; i < queens.size(); ++i)
            board[queens[i][0]][queens[i][1]] = 1;
        check(board, king[1], king[0], "left");
        check(board, king[1], king[0], "right");
        check(board, king[1], king[0], "down");
        check(board, king[1], king[0], "up");
        check(board, king[1], king[0], "dlu");
        check(board, king[1], king[0], "dld");
        check(board, king[1], king[0], "dru");
        check(board, king[1], king[0], "drd");
        return _ans;
    }
};