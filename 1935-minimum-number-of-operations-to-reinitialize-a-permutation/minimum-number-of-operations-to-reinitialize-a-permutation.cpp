class Solution {
public:
    void solve(vector<int>& perm, vector<int>& orig, int& ans)
    {
        if (ans && perm == orig) return;
        ++ans;
        int n = perm.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            if (i%2) arr[i]  = perm[ n / 2 + (i - 1) / 2];
            else arr[i] = perm[i / 2];
        }
        solve(arr, orig, ans);
    }
    int reinitializePermutation(int n) {
       vector<int> perm(n), orig(n);
       int ans = 0;

       for (int i = 0; i < n; ++i)
        perm[i] = orig[i] = i;
        solve(perm, orig, ans);
        return ans;
    }
};