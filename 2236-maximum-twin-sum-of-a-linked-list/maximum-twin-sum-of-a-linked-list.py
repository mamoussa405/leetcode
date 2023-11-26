# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head

        while fast and fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next

        def reverse_list(currNode: Optional[ListNode], parent: Optional[ListNode]) -> Optional[ListNode]:
            if currNode.next == None:
                currNode.next = parent
                return currNode
            newHead: ListNode = reverse_list(currNode.next, currNode)
            currNode.next = parent
            return newHead
        
        leftHead: Optional[ListNode] = reverse_list(slow.next, None)
        ans: int = 0
        while head and leftHead:
            ans = max(ans, head.val + leftHead.val)
            head = head.next
            leftHead = leftHead.next
        return ans

        