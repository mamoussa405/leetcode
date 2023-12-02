# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.firstTree = []
        self.secondTree = []

    def dfs(self, currNode: TreeNode, arr: list[int]):
        if not currNode: return
        self.dfs(currNode.left, arr)
        arr.append(currNode.val)
        self.dfs(currNode.right, arr)
    
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        self.dfs(root1, self.firstTree)
        self.dfs(root2, self.secondTree)
        ans: list[int] = []
        i: int = 0
        j: int = 0

        while i < len(self.firstTree) and j < len(self.secondTree):
            if self.firstTree[i] <= self.secondTree[j]:
                ans.append(self.firstTree[i])
                i += 1
            else:
                ans.append(self.secondTree[j])
                j += 1
        
        while i < len(self.firstTree):
            ans.append(self.firstTree[i])
            i += 1
        
        while j < len(self.secondTree):
            ans.append(self.secondTree[j])
            j += 1
        return ans
            