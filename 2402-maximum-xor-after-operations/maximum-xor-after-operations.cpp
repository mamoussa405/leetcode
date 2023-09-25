class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;

        for (int& n : nums)
            ans |= n;
        return ans;
    }
};