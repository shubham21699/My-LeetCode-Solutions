class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size();
        if(minutes == n) return accumulate(customers.begin(), customers.end(), 0);
        
        // When the owner is not grumpy, we count all the customers as satisfied.
        // We then use the sliding window to count additionally satisfied customers (additional_satisfied)
        // if the owner start behaving at minute i.
        // We track the maximum additional satisfied customers (maximum_additional_satisfied).
        // Finally, return satisfied + maximum_additional_satisfied as result.
        
        int satisfied = 0;
        int additional_satisfied = 0;
        int maximum_additional_satisfied = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            satisfied += !grumpy[i]*customers[i];
            additional_satisfied += grumpy[i]*customers[i];
            
            if(i >= minutes) {
                additional_satisfied -= grumpy[i-minutes]*customers[i-minutes];
            }
            
            maximum_additional_satisfied = max(maximum_additional_satisfied, additional_satisfied);
        }
        
        return satisfied + maximum_additional_satisfied;
    }
};