class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        
        // First, we count numbers using a hash map mp.
        // For numbers a, b and c, we can form mp[a] * mp[b] * mp[c] unique triplets.
        
        unordered_map<int, int> mp;
        for(int i=0 ; i<n ; i++) mp[nums[i]]++;
        
        int leftCount = 0;
        int rightCount = n;
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            
            rightCount -= it->second;
            count += leftCount * it->second * rightCount;
            leftCount += it->second;
            
        }
        
        return count;
        
        
//         // OR:
//         for(int i=0 ; i<n-2 ; i++) {
//             for(int j=i+1 ; j<n-1 ; j++) {
//                 for(int k=j+1 ; k<n ; k++) {
//                     if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
//                         count++;
//                 }
//             }
//         }
        
//         return count;
    }
};