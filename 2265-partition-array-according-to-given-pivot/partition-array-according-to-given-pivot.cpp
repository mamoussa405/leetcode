class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, greater;
        vector<int> ans;
        int num_pivot{0};
    
        for (int i = 0; i < nums.size(); ++i)
        {
                if (nums[i] < pivot)
                    less.push_back(nums[i]);
                else if (nums[i] > pivot)
                    greater.push_back(nums[i]);
                else
                    ++num_pivot;
        }
        for (int& n : less)
            ans.push_back(n);
        while (num_pivot--)
            ans.push_back(pivot);
        for (int& n : greater)
            ans.push_back(n);
        return ans;
    }
};