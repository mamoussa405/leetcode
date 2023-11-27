# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.root.val = 0
        self.cach: set[int] = {0}

        def recover(currNode: Optional[TreeNode]):
            if currNode == None: return
            if currNode.left:
                currNode.left.val = 2 * currNode.val + 1
                self.cach.add(currNode.left.val)
            if currNode.right:
                currNode.right.val = 2 * currNode.val + 2
                self.cach.add(currNode.right.val)
            recover(currNode.left)
            recover(currNode.right)

        recover(self.root)

    def find(self, target: int) -> bool:
        if target in self.cach:
            return True
        return False


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)