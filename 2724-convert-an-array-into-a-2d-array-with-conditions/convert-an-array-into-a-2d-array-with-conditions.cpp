class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> freq; 
        vector<vector<int>> ans;
        int size = nums.size();

        for(int& n : nums)
            freq[n]++;

        while (size) 
        {
            vector<int> tmp;
            for (auto& it : freq)
                if  (it.second)
                {
                    tmp.push_back(it.first);
                    --size;
                    it.second--;
                }
            ans.push_back(tmp);
        }
        return ans; 
    }
};