class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int _max = 0;
        vector<bool> ans(candies.size()) ;

        for (int& n : candies)
            _max = max(_max, n);
        for (int i = 0; i < candies.size(); ++i)
            ans[i] = (candies[i] + extraCandies >= _max);
        return ans;
    }
};