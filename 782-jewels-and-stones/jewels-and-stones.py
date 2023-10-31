class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        ans: int = 0
        st: set[int] = set()

        for c in jewels:
            st.add(c)
        for c in stones:
            if c in st:
                ans += 1
        return ans 