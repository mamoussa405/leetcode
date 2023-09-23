class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int origCapacity = capacity;

        for (int i = 0; i < plants.size();)    
        {
            if (plants[i] <= capacity)
            {
                ++ans;
                capacity -= plants[i];
                ++i;
            } else {
                ans += (i * 2);
                capacity = origCapacity;
            }
        }
        return ans;
    }
};