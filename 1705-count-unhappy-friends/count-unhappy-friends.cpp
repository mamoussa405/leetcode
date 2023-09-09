class Solution {
public:
    bool pair_is_prefered(vector<vector<int>>& opt_pref, int curr, int pair, int other)
    {
        if (opt_pref[curr][other] == -1)
            return 1;
        return opt_pref[curr][pair] < opt_pref[curr][other];
    }
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& p) {
        int ans = 0;
        vector<vector<int>> opt_pref(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n - 1; ++j)
                opt_pref[i][pref[i][j]] = j;

        for (int i = 0; i < p.size(); ++i)
        {
            bool p1_unhappy = 0;
            bool p2_unhappy = 0;
            for (int j = 0; j < p.size(); ++j)
            {
                if (j == i) continue;
                if (!p1_unhappy && !pair_is_prefered(opt_pref, p[i][0], p[i][1], p[j][0])
                && !pair_is_prefered(opt_pref, p[j][0], p[j][1], p[i][0]))
                {
                    ++ans;
                    p1_unhappy = 1;
                }
                else if (!p1_unhappy && !pair_is_prefered(opt_pref, p[i][0], p[i][1], p[j][1])
                && !pair_is_prefered(opt_pref, p[j][1], p[j][0], p[i][0]))
                {
                    ++ans;
                    p1_unhappy = 1;
                }
                if (!p2_unhappy && !pair_is_prefered(opt_pref, p[i][1], p[i][0], p[j][0])
                && !pair_is_prefered(opt_pref, p[j][0], p[j][1], p[i][1]))
                {
                    ++ans;
                    p2_unhappy = 1;
                }
                else if (!p2_unhappy && !pair_is_prefered(opt_pref, p[i][1], p[i][0], p[j][1])
                && !pair_is_prefered(opt_pref, p[j][1], p[j][0], p[i][1]))
                {
                    ++ans;
                    p2_unhappy = 1;
                }
                if (p1_unhappy && p2_unhappy) break;
            }
        }
        return ans;
    }
};