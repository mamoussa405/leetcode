class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, long long> f;
        priority_queue<long long> pq;
        long long ans = 0;

        for (vector<int>& r : roads) {
            ++f[r[0]];
            ++f[r[1]];
        }

        for (auto& e : f) {
            pq.push(e.second);
        }
        while (!pq.empty()) {
            long long curr = pq.top();
            pq.pop();
            ans += (curr * n);
            --n;
        }
        return ans;
    }
};