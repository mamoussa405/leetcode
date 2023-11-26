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
        
        curr: LisNode = slow.next
        prev: ListNode = None

        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        
        ans: int = 0
        while head and prev:
            ans = max(ans, head.val + prev.val)
            head = head.next
            prev = prev.next
        return ans

        