class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       int s = -1, f = -1;

       for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] % 2) {
            if (s == -1) {
                s = i;
            } else {
                f = i;
            }
        } else {
            s = -1;
            ++f;
        }
        if (s != -1 && f != -1 && f - s == 2)
            return true;
       } 
       return false;
    }
};