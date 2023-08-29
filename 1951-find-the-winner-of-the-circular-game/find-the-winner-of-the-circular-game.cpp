class Solution {
public:
    int next_player(vector<int>& cir, int curr, int k,  int n)
    {
        --k;
        while (k)
        {
            ++curr;
            curr %= n;
            if (!curr) curr = n;
            if (cir[curr])  --k;
        }
        return curr;
    }
    int findTheWinner(int n, int k) {
        vector<int> cir(n + 1, 1);
        int s = n;
        int curr = 1;

        while (s > 1)
        {
            curr = next_player(cir, curr, k, n);
            cir[curr] = 0;
            while (!cir[curr])
            {
                ++curr;
                curr %= n;
                if (!curr) curr = n;
            }
            --s;
        }
        for (int i = 1; i <= n; ++i)
            if (cir[i]) return i;
        return 0;
    }
};