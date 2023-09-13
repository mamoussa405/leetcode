class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> orig = nums;
        sort(nums.begin(), nums.end());
        vector<int> pref_nums(101, -1);
        vector<int> ans(orig.size());

        for (int i = 0; i < nums.size(); ++i)
            pref_nums[nums[i]] = (pref_nums[nums[i]] == -1) ? i : pref_nums[nums[i]];
        for (int i = 0; i < ans.size(); ++i)
            ans[i] = pref_nums[orig[i]];
        return ans;
    }
};