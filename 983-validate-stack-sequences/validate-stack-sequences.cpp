class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;

        while (i < pushed.size() || j < pushed.size())
        {
            if (i < pushed.size()) s.push(pushed[i++]);
            while (!s.empty()  && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
            if (i == pushed.size() && !s.empty()) return 0;
        }
        return 1; 
    }
};