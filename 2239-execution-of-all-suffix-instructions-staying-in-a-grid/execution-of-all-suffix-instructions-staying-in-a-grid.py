class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        m: int = len(s)
        ans: List[int] = [0] * m

        for i in range(m):
            j: int = i
            inst: int = 0
            nextX: int = startPos[1]
            nextY: int = startPos[0]
            while j < m:
                if s[j] == 'R': nextX += 1
                elif s[j] == 'L': nextX -= 1
                elif s[j] == 'D': nextY += 1
                else: nextY -= 1
                if nextX >= 0 and nextX < n and nextY >= 0 and nextY < n: inst += 1
                else: break
                j += 1
            ans[i] = inst
        return ans