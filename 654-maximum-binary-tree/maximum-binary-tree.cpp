/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
public:
    TreeNode* solve(vector<int>& nums, int start, int end) 
    {
        if (start > end)
            return nullptr;
        int idx = start;

        for (int i  = start; i <= end; ++i) 
            if (nums[i] > nums[idx])
                idx = i;
        TreeNode* curr = new TreeNode(nums[idx]);
        curr->left = solve(nums, start, idx - 1);
        curr->right = solve(nums, idx + 1, end);
        return curr;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,  0, nums.size() - 1);
    }
};