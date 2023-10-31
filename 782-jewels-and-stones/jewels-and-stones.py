class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        ans: int = 0

        for c in stones:
            if c in jewels:
                ans += 1
        return ans 