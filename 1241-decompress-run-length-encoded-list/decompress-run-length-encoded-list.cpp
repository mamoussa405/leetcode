class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;            
        int i = 0;

        while (i < nums.size())
        {
            int freq = nums[i];
            int val = nums[i + 1];
            while (freq--)
                ans.push_back(val);
            i += 2;
        }
        return ans;
    }
};