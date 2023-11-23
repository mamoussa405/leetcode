class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        map: dict[int, int] = defaultdict(list)

        for i in range(len(mat)):
            for j in range(len(mat[0])):
                map[i - j].append(mat[i][j])
        
        for v in map.values():
            v.sort()
        
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                mat[i][j] = map[i-j].pop(0)
        return mat