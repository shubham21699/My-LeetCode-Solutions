class Solution {
    bool isPossible(vector<int>& weights, int days, int capacity) {
        
        int n = weights.size();
        int sum = 0;
        int day = 1;
        
        for(int i=0 ; i<n ; i++) {
            sum += weights[i];
            
            if(sum > capacity) {
                day++;
                sum = weights[i];
            }
            
        }
        
        if(day <= days) return true;
        return false;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        if(n == days) return *max_element(weights.begin(), weights.end());
        if(days == 1) return accumulate(weights.begin(), weights.end(), 0);
        
        int totalCapacity = accumulate(weights.begin(), weights.end(), 0);;
        int maxCapacityPerDay = totalCapacity;
        
        int low = *max_element(weights.begin(), weights.end());
        int high = totalCapacity;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            if(isPossible(weights, days, mid)) {
                maxCapacityPerDay = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return maxCapacityPerDay;
    }
};