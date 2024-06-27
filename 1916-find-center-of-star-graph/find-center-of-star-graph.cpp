class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> freq;
        int ans;
        int prev = 0;

        for(auto& e:edges) {
            ++freq[e[0]];
            ++freq[e[1]];
        }
        for(auto& n:freq) {
            if (n.second > prev) {
                ans = n.first;
                prev = n.second;
            }
        }
        return ans;
    }
};