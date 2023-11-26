class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        xor_arr: list[int] = [0] * len(nums)
        ans: list[int] = []

        xor_arr[0] = nums[0]
        for i in range(1, len(nums)):
            xor_arr[i] = xor_arr[i-1] ^ nums[i]

        mask: int = 0
        i: int = 0
        while i < maximumBit:
            mask |= (1 << i)
            i += 1

        for j in range(len(xor_arr) - 1, -1, -1):
            rev: int = (~xor_arr[j] & ((1 << maximumBit) - 1))
            tmp: int = xor_arr[j] ^ mask
            tmp2: int = xor_arr[j] ^ rev
            tmp3: int = xor_arr[j] ^ (mask&rev)

            if max(tmp, tmp2, tmp3) == tmp:
                ans.append(mask)
            elif max(tmp, tmp2, tmp3) == tmp2:
                ans.append(rev)
            else:
                ans.append(mask&rev)

        return ans