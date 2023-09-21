class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> activeMinutes;
        vector<int> ans(k, 0);

        for (int i = 0; i < logs.size(); ++i)
            activeMinutes[logs[i][0]].insert(logs[i][1]);

        for (auto& it : activeMinutes) 
            ++ans[it.second.size() - 1];
        return ans;
    }
};