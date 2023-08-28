class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m: int = len(grid)
        n: int = len(grid[0])
        onesRow: List[int] = [0] * m
        zerosRow: List[int] = [0] * m
        onesCol: List[int] = [0] * n
        zerosCol: List[int] = [0] * n
        diff: List[List[int]] = [[0] * n for _ in range(m)]

        for r in range(m):
            zeros , ones = 0, 0
            for  c in range(n):
                zeros += grid[r][c] == 0
                ones += grid[r][c] == 1
            onesRow[r] , zerosRow[r] = ones, zeros
        for c in range(n):
            zeros, ones = 0, 0
            for r in range(m):
                zeros += grid[r][c] == 0
                ones += grid[r][c] == 1
            onesCol[c], zerosCol[c] = ones, zeros
        for i in range(m):
            for j in range(n):
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j]
        return diff
        