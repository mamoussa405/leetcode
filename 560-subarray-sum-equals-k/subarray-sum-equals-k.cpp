class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m = {{0, 1}};
        int sum = 0;
        int ans = 0;

        for (int& n : nums) {
            sum += n;
            if (m.count(sum - k))
                ans += m[sum - k];
            m[sum] += 1;
        }
        return ans;
    }
};