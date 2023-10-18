class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ex_space(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            ex_space[((i + k) % nums.size())] = nums[i];
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] = ex_space[i];
        }
    }
};