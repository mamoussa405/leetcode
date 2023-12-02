class Solution:
        
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        class Group:
            def __init__(self, buffer: list[int]):
                self.buffer = buffer
                self.index = 0
            
            def getNextElement(self) -> int:
                res: int = self.buffer[self.index]
                self.index += 1
                return res

        sortedNums: list[int] = sorted(nums)
        groupsList: list[Group] = []
        tmpList: list[int] = [sortedNums[0]]
        groupIndex: dist[int, int] = {sortedNums[0] : 0}
        index: int = 0
        ans: list[int] = []

        for i in range(1, len(sortedNums)):
            if sortedNums[i] - sortedNums[i - 1] <= limit:
                groupIndex[sortedNums[i]] = index
                tmpList.append(sortedNums[i])
            else:
                index += 1
                groupsList.append(Group(tmpList.copy()))
                tmpList = [sortedNums[i]]
                groupIndex[sortedNums[i]] = index
        groupsList.append(Group(tmpList.copy()))
        for e in nums:
            ans.append(groupsList[groupIndex[e]].getNextElement())
        return ans