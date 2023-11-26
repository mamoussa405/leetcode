# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        arr: list[int] = []
        start: int = 0
        end: int = 0
        ans: int = 0

        while head:
            arr.append(head.val)
            head = head.next
        end = len(arr) - 1
        while start < end:
            ans = max(ans, (arr[start] + arr[end]))
            start += 1
            end -= 1
        return ans
        