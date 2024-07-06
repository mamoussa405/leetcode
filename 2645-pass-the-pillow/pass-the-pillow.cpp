class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n) return time + 1;
        int r = (time % (n - 1));
        int m = (time / (n - 1));

        return m%2 ? n - r : r + 1;
    }
};