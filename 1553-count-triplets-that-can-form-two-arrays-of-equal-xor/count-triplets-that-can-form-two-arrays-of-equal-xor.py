class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n: int = len(arr)
        prefix: list[int] = [0] * n
        prefix[0] = arr[0]
        ans: int = 0

        for i in range(1, n):
            prefix[i] = prefix[i - 1] ^ arr[i]

        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j, n):
                    a: int = 0
                    b: int = 0
                    if i == j - 1:
                        a = arr[i]
                    elif i > 0:
                        a = prefix[i - 1] ^ prefix[j - 1]
                    else:
                        a = prefix[j - 1]
                    if j == k:
                        b = arr[j]
                    else:
                        b = prefix[k] ^ prefix[j - 1]
                    ans += (a == b)
        return ans