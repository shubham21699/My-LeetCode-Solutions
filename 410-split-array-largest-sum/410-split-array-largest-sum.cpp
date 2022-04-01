class Solution {
    bool isPossible(vector<int>& nums, int current, int m) {
        
        int possibleCuts = 1;
        int sum = 0;
        
        for(int i=0 ; i<nums.size() ; i++) {
            sum += nums[i];
            
            // If this cose arrise, then no partition is possible so return false.
            if(nums[i] > current) return false;
            
            // If this arrise then a cut has to be made so increase cut count.
            if(sum > current) {
                sum = nums[i];
                possibleCuts++;
            }
        }
        
        // If noOfCuts to be made are <= m then return true.
        return possibleCuts <= m;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();
        if(m == 1) return accumulate(nums.begin(), nums.end(), 0);
        if(n == m) return *max_element(nums.begin(), nums.end());
        
        int lowest = *min_element(nums.begin(), nums.end());
        int highest = accumulate(nums.begin(), nums.end(), 0);
        int result = lowest;
        
        while(lowest <= highest) {
            
            int mid = lowest + (highest - lowest)/2;
            
            // If cuts to be made are possible then update result with mid because is the min of max sum .
            if(isPossible(nums, mid, m)) { 
                result = mid;
                highest = mid-1;
            }
            else lowest = mid+1;
            
        }
        
        return result;
    }
};