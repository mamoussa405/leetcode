class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> nums_index;

        for (int i = 0; i < nums.size(); ++i) 
            nums_index[nums[i]] = i;

        for (vector<int>& v : operations)
        {
            nums[nums_index[v[0]]] = v[1];
            nums_index[v[1]] = nums_index[v[0]];
        }
        return nums;
    }
};