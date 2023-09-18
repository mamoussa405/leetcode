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
public:
    void solve(TreeNode* root, int n)
    {
        if (n < root->val)
        {
            if (root->left == nullptr)
            {
                root->left = new TreeNode(n);
                return;
            }
            solve(root->left, n);
        }
        else
        {
            if (root->right == nullptr)
            {
                root->right = new TreeNode(n);
                return;
            }
            solve(root->right, n);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& pr) {
        TreeNode* root = new TreeNode(pr[0]);
        for (int i = 1; i < pr.size(); ++i)
            solve(root, pr[i]); 
        return root;
    }
};