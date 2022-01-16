class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int capacity = 0;
        int result = 0;
        int total = 0;
        
        for(int i=0 ; i<n ; i++) {
            capacity += (gas[i] - cost[i]);
            if(capacity < 0) {
                total += capacity;
                capacity = 0;
                result = i+1;
            }
        }
        
        total += capacity;
        
        return total<0 ? -1 : result;
    }
};