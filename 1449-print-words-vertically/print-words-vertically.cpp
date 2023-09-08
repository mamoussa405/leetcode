class Solution {
public:
    vector<string> split(string s)
    {
        stringstream ss(s);
        string tmp;
        vector<string> ans;
        while (getline(ss, tmp, ' '))
            ans.push_back(tmp);
        return ans;
    }
    vector<string> printVertically(string s) {
        vector<string> res = split(s), ans;
        int max_size = 0;

        for (string& ss : res)
            max_size = max(max_size, (int)ss.size());
        for (int i = 0; i < max_size; ++i)
        {
            string tmp;
            bool found_char = 0;
            for (int j = 0; j < res.size(); ++j)
                tmp += (i >= res[j].size()) ? ' ':res[j][i];
            while (tmp.back() == ' ')
                tmp.pop_back();
            ans.push_back(tmp);
        }
        return ans;
    }
};