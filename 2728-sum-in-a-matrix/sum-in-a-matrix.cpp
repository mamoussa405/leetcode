class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int ans = 0;
        int m = nums.size();
        int n = nums[0].size();
        for (auto& r : nums)  
            sort(r.rbegin(), r.rend());

        for (int r = 0; r < n; ++r)
        {
            int _max = 0;
            for (int c = 0; c < m; ++c)
                _max = max(_max, nums[c][r]);
            ans += _max;
        }
        return ans;
    }
};