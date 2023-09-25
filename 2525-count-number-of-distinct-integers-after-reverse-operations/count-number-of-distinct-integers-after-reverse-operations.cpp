class Solution {
public:
    int rev(int n)
    {
        int res = 0;
        while (n)
        {
            res = (res * 10) + (n%10);
            n /= 10;
        }
        return res;
    }

    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;

        for (int& n : nums) 
        {
            s.insert(n);
            s.insert(rev(n));
        }
        return s.size();
    }
};