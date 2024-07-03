class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        int l = 0;
        int r = n - 4; 
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        while (l < 4) {
            ans = min(ans, nums[r] - nums[l]);
            ++l;
            ++r;
        }
        return ans;
        // 0 1 5 10 14
    }
};