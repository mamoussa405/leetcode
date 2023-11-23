class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        origX: int = 0
        origY: int = 1
        m: int = len(mat)
        n: int = len(mat[0])

        while origX < n:
            x: int = origX
            y: int = 0
            tmpList: list[int] = []
            while x < n and y < m:
                tmpList.append(mat[y][x])
                x += 1
                y += 1
            tmpList.sort()
            x = origX
            y = 0
            for num in tmpList:
                mat[y][x] = num
                y += 1
                x += 1
            origX += 1

        while origY < m:
            x: int = 0
            y: int = origY
            tmpList: list[int] = []
            while x < n and y < m:
                tmpList.append(mat[y][x])
                x += 1
                y += 1
            tmpList.sort()
            x = 0
            y = origY
            for num in tmpList:
                mat[y][x] = num
                y += 1
                x += 1
            origY += 1
        return mat