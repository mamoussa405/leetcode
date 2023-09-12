class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;

        // for (int& n : hours) 
        //     ans += (n >= target);
        for (int i = 0; i < hours.size(); ++i)
            ans += (hours[i] >= target);
        return ans;
    }
};