class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());

        for (int i = 0; i < l.size(); ++i)
        {
            vector<int> tmp(r[i] - l[i] + 1);
            for (int j = l[i], k = 0; j <= r[i]; ++j, ++k)
                tmp[k] = nums[j];
            sort(tmp.begin(), tmp.end());
            if (tmp.size() == 1)
                ans[i] = 1;
            else
            {
                int diff = tmp[1] - tmp[0];
                bool is_valid = 1;
                for (int j = 2; j < tmp.size(); ++j)
                    if (tmp[j] - tmp[j - 1] != diff)
                    {
                        is_valid = 0;
                        break;
                    }
                ans[i]  = is_valid;
            }
        }
        return ans;
    }
};