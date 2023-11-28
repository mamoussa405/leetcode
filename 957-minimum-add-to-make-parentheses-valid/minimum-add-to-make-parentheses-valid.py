class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        if len(s) == 0: return 0
        stack: list[str] = []
        ans: int = 0

        for c in s:
            if c == '(':
                stack.append(c)
            elif not len(stack): ans += 1
            else: stack.pop()
        ans += len(stack)
        return ans