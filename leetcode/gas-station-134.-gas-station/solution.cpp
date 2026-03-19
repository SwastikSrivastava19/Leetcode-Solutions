// Problem: 134. Gas Station
// URL: https://leetcode.com/problems/gas-station/
// Language: cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0 , curr = 0 , start = 0;

        for(int i=0; i<gas.size(); i++){
            int diff = gas[i] - cost[i];

            curr += diff;
            total += diff;

            if(curr < 0){
                start = i + 1;
                curr = 0;
            }
            // if(total < 0) return -1;
        }
        if(total < 0) return -1;
        return start;
    }
};
