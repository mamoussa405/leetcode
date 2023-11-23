# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getNumberOfNodes(self, root: Optional[TreeNode], ans: list[int]) -> tuple[int, int]:
        if root == None: return [0, 0]
        left: tuple[int, int] = self.getNumberOfNodes(root.left, ans)
        right: tuple[int, int] = self.getNumberOfNodes(root.right, ans)
        nodes: int = left[0] + right[0] + 1
        nodesSum: int = left[1] + right[1] + root.val
        avg: int = math.floor(nodesSum / nodes)
        if avg == root.val: ans[0] += 1
        return [nodes, nodesSum]

    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        ans: list[int] = [0]
        self.getNumberOfNodes(root, ans)
        return ans[0]