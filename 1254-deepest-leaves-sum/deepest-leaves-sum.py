# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxHeight = 0
        self.ans = 0

    def solution(self, root: Optional[TreeNode], h: int):
        if root == None: return
        if  h + 1 == self.maxHeight:
            self.ans += root.val
        elif h + 1 > self.maxHeight:
            self.ans = root.val
            self.maxHeight = h + 1
        self.solution(root.left, h + 1)
        self.solution(root.right, h + 1)

    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.solution(root, 0)
        return self.ans
