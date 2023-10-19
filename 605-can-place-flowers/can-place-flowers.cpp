class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        if (!n) return 1;
        if (m == 1) return !flowerbed[0];
        for (int i = 0; i < flowerbed.size() && n; ++i) {
            if (flowerbed[i]) continue;
            if (!i) {
                if (flowerbed[i + 1]) continue;
                flowerbed[i] = 1;
                --n;
            }
            else if (i == m - 1) {
                if (flowerbed[i - 1]) continue;
                --n;
            } else {
                if (flowerbed[i-1] || flowerbed[i+1]) continue;
                flowerbed[i] = 1;
                --n;
            }
        }
        return !n;
    }
};