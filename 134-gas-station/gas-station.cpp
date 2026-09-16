class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int curr = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];

            curr += gas[i] - cost[i];

            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }

        if (total_gas < total_cost) {
            return -1;
        }

        return start;
    }
};