class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int capacity = 0;
        int start_point = 0;
        int deficit_amount = 0;
        
        for(int i=0 ; i<n ; i++) {
            capacity += (gas[i] - cost[i]);
            
            if(capacity < 0) {
                deficit_amount += capacity;
                capacity = 0;
                start_point = i+1;
            }
        }
        
        deficit_amount += capacity;
        
        return deficit_amount<0 ? -1 : start_point;
    }
};