class Solution {
public:
    bool pair_is_prefered(vector<vector<int>>& pref, int curr, int pair, int other)
    {
        int pair_index;
        int other_index = -1;

        for (int i = 0; i < pref[curr].size(); ++i)
        {
            if (pref[curr][i] == pair)
                pair_index = i;
            else if (pref[curr][i] == other)
                other_index = i;
        }
        if (other_index == -1) return true;
        return pair_index < other_index;
    }
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& p) {
        int ans = 0;

        for (int i = 0; i < p.size(); ++i)
        {
            bool p1_unhappy = 0;
            bool p2_unhappy = 0;
            for (int j = 0; j < p.size(); ++j)
            {
                if (j == i) continue;
                if (!p1_unhappy && !pair_is_prefered(pref, p[i][0], p[i][1], p[j][0])
                && !pair_is_prefered(pref, p[j][0], p[j][1], p[i][0]))
                {
                    ++ans;
                    p1_unhappy = 1;
                }
                else if (!p1_unhappy && !pair_is_prefered(pref, p[i][0], p[i][1], p[j][1])
                && !pair_is_prefered(pref, p[j][1], p[j][0], p[i][0]))
                {
                    ++ans;
                    p1_unhappy = 1;
                }
                if (!p2_unhappy && !pair_is_prefered(pref, p[i][1], p[i][0], p[j][0])
                && !pair_is_prefered(pref, p[j][0], p[j][1], p[i][1]))
                {
                    ++ans;
                    p2_unhappy = 1;
                }
                else if (!p2_unhappy && !pair_is_prefered(pref, p[i][1], p[i][0], p[j][1])
                && !pair_is_prefered(pref, p[j][1], p[j][0], p[i][1]))
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