class Solution:
    def minSteps(self, s: str, t: str) -> int:
        # l -> 1, e -> 3, t -> 1, c -> 1, o -> 1, d -> 1
        # p -> 1, r -> 1, a -> 1, c -> 2, t -> 1, i -> 1, e -> 1
        # 1, 2, 1, 1
        s_freq: defaultdict[str, int] = defaultdict(int)
        t_freq: defaultdict[str, int] = defaultdict(int)
        ans: int = 0

        for c in s:
            s_freq[c] += 1

        for c in t:
            t_freq[c] += 1
        
        for c in s_freq:
            if t_freq[c] < s_freq[c]:
                ans += (s_freq[c] - t_freq[c])
        return ans