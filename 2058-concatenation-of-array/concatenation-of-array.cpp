class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size() * 2;
        vector<int> ans(n);
        int i = 0;
        for (int& n : nums)
            ans[i] = n,
            ++i;
        for (int& n : nums)
            ans[i] = n,
            ++i;
        return ans;
    }
};