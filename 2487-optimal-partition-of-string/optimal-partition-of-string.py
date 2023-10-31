class Solution:
    def partitionString(self, s: str) -> int:
        ans: int = 1
        save: set[str] = set()

        for c in s:
            if c in save:
               save.clear()
               ans += 1
            save.add(c)
        return ans 