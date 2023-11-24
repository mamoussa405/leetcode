class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans: list[list[int]] = []
        tmp: list[int] = []
        n: int = len(graph) - 1

        def dfs(currNode: int):
            if currNode == n:
                ans.append(tmp.copy())
                return
            
            for node in graph[currNode]:
                tmp.append(node)
                dfs(node)
                tmp.pop()
        
        tmp.append(0)
        dfs(0)
        return ans