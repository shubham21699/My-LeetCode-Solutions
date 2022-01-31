class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) {
            if(nums[0] != 1) return 1;
            return 2;
        }
        
        // O(n) Approach:
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == i+1) continue;
            
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] != i+1) return i+1;
        }
        
        return n+1;
        
        
//         OR: O(nLogn)
//         int result = 1;
//         sort(nums.begin(), nums.end()); // O(nLogn)
//         nums.erase(unique(nums.begin(), nums.end()), nums.end());
//         n = nums.size();
        
//         for(int i=0 ; i<n ; i++) {  // O(n)
//             if(nums[i] > 0 && nums[i] != result) {
//                 break;
//             }
//             if(nums[i] > 0 && nums[i] == result) {
//                 result++;
//             }
//         }
        
//         return result;

//         OR: Using Hash Table (Takes extra space)    
//         unordered_map<int, int> m;
//         for(int i=0 ; i<n ; i++) {
//             m[nums[i]]++;
//         }
        
//         int result = 0;
//         for(int i=1 ; i<=n ; i++) {
//             if(m.find(i) == m.end()) {
//                 result = i;
//                 break;
//             }
//         }
        
//         return result==0 ? n+1 : result;
    }
};