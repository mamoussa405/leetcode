class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       long long last_order_end;
       long long sum = 0;

       last_order_end = customers[0][0] + customers[0][1];
       sum = customers[0][1];
       for (int i = 1; i < customers.size(); ++i)
       {
            if (customers[i][0] >= last_order_end)
                last_order_end = customers[i][0] + customers[i][1];
            else
                last_order_end += customers[i][1];
           sum += (last_order_end - customers[i][0]);
       } 
       cout << sum << endl;
       return (sum / (double)customers.size());
    }
    // last_order_end = 19
    // sum = 3 + 2 + 6 + 5 + 3 + 1
    // sum = 20 / 6
};