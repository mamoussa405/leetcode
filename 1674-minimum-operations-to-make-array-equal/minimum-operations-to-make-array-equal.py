class Solution:
    def minOperations(self, n: int) -> int:
        # n = 1 -> [1] 0
        # n = 2 -> [1, 3] 1 
        # n = 3 -> [1, 3, 5] 2 3 2
        # n = 4 -> [1, 3, 5, 7] 4
        # n = 5 -> [1, 3, 5, 7, 9] 6
        # n = 6 -> [1, 3, 5, 7, 9, 11] 9
        # n = (2*i) + 1
        # n - 1 = (2 * i)
        # n - 1 / 2 = i
        # i = 3 - 1 / 2 = 1
        # i = 4 - 1 / 2 = 1.5 no 4
        # i = 5 - 1 / 2 = 2
        # i = 6 - 1 / 2 = 
        i: int = math.floor((n - 1) / 2) + 1
        ans: int = 0
        
        while i < n:
            ans += (((2 * i) + 1) - n)
            i += 1
        return ans