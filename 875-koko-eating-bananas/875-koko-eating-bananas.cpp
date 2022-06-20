class Solution {
    bool isPossible(vector<int>& piles, int h, int k) {
        
        long long count = 0;
        
        for(int i=0 ; i<piles.size() ; i++) {
            count += ceil(piles[i]*1.0 / k);
            
            if(count > h) return false;
        }
        
        return count <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        if(n == h) return *max_element(piles.begin(), piles.end());
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = 0;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            if(isPossible(piles, h, mid)) {
                result = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        
        return result;
    }
};