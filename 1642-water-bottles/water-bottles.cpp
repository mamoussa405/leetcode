class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans{0};
        int full = numBottles;
        int empty = full;

        while (empty >= numExchange)
        {
            ans += full;
            full = empty / numExchange;
            empty = empty % numExchange + full;
        }
        ans += full;
        return ans;
    }
};