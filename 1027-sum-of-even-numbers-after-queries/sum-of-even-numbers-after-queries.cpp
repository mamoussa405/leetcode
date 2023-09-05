class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> is_even(n, 0);
        vector<int> ans;
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            if (abs(nums[i])%2 == 0)
            {
               sum += nums[i];
               is_even[i] = 1;
            }
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            int index = queries[i][1];
            int val = queries[i][0];
            if (is_even[index]) sum -= nums[index];
            nums[index] += val;
            if (abs(nums[index])%2 == 0)
            {
                sum += nums[index];
                is_even[index] = 1;
            } else is_even[index] = 0;
            ans.push_back(sum);
        }
        return ans;
    }
};