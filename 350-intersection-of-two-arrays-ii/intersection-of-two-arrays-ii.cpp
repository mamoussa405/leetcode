class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> f;
       vector<int> ans;

       for (int& n : nums1)
        ++f[n];

        for(int& n : nums2) {
            if (f[n]) {
                ans.push_back(n);
                --f[n];
            }
        }  
        return ans;
    }
};