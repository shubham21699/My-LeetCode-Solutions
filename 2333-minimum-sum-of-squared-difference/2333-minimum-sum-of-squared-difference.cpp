class Solution {
    bool isPossible(vector<int>& diff, int cut, long long& k) {
        
        long long total = 0;
        
        for(int i=0 ; i<diff.size() ; i++) {
            if(diff[i] > cut) total += (diff[i] - cut);
        }
        
        return total <= k;
    }
    
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n = nums1.size();
        vector<int> diff(n, 0);
        
        for(int i=0 ; i<n ; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        
        sort(diff.begin(), diff.end());
        long long k = k1 + k2;
        
        // Using binary search, we find max value of diff of abs(nums1[i] - nums2[i]) 
        // which is possible for given k.
        int left = 0;
        int right = diff.back();
        int val = 0;
        
        while(left <= right) {
            
            int mid = left + (right - left) / 2;
            
            if(isPossible(diff, mid, k)) {
                val = mid;
                right = mid-1;
            }
            else left = mid+1;
            
        }
        
        // Reducing all abs(nums1[i] - nums2[i]) and also reducing k by that value.
        for(int i=0 ; i<n ; i++) {
            if(diff[i] > val && k > 0) {
                int x = diff[i] - val;
                k -= x;
                diff[i] -= x;
            }
        }
  
        priority_queue<int> pq;
        
        for(int i=0 ; i<n ; i++) pq.push(diff[i]);
        
        // Now removing rest of the extra k's from the array to get optimal ans
        while(k && !pq.empty()) {
            int x = pq.top();
            pq.pop();
            k--;
            x--;
            
            if(x > 0) pq.push(x);
        }
        
        if(pq.empty()) return 0;
        
        long long ans = 0;
        
        while(!pq.empty()) {
            ans += pow(pq.top(), 2);
            pq.pop();
        }
        
        return ans;
    }
};