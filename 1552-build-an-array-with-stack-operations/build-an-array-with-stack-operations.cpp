class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        stack<int> s;
        vector<string> ans;
        int i = 0;

        while (stream <= n && i < target.size())
        {
            if (s.empty())
            {
                ans.push_back("Push");
                s.push(stream++);
                continue;
            }
            if (target[i] != s.top())
            {
                s.pop();
                s.push(stream++);
                ans.push_back("Pop");
                ans.push_back("Push");
            } else 
            {
                s.push(stream++);
                if (i == target.size() - 1)
                    break;
                ans.push_back("Push");
                ++i;
            }
        }
        return ans;
    }
};