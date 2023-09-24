class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size() / 3;
        int i = (n*3) - 2;
        int ans = 0;

        while (n--)
        {
            ans += piles[i];
            i -= 2;
        }
        return ans;
    }
};