# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0
    
    def convertTree(self, root: Optional[TreeNode]):
        if root == None: return
        self.convertTree(root.right)
        root.val += self.sum
        self.sum = root.val
        self.convertTree(root.left)
        return root.val

    def bstToGst(self, root: TreeNode) -> TreeNode:
       self.convertTree(root)
       return root 