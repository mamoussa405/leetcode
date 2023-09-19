class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> indexInA(n + 1, -1);
        vector<int> ans(n);

        for (int i = 0; i < n; ++i)
            indexInA[A[i]] = i;

        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for (int j = i; j >= 0; --j)
                if (indexInA[B[j]] <= i)
                    ++cnt;
            ans[i] = cnt;
        }
        return ans; 
    }
};