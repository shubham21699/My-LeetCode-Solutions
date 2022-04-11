class Solution {
//     void check(vector<int>& nums, int k, int& count, int index, int n, int sum) {
        
//         if(index >= n) return;
        
//         for(int i=index ; i<n ; i++) {
//             sum += nums[i];
//             if(sum % k == 0) count++;
//         }
        
//         check(nums, k, count, index+1, n, 0);
//     }
    
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return nums[0]%k == 0;
        
        int count = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1; // Initially sum is 0 amd (0 % k) == 0.
        
        for(int i=0 ; i<n ; i++) {
            
            sum += nums[i];
            
            int remainder = sum % k;
            
            //ALWAYS CHOOSE THE POSITIVE REMAINDER
            // The division of a negative number by a positive can yield positive and negative remainders.
            // Some languages allow negative remainders, that's not right. In order for me to ensure 
            // I'm taking the correct remainder, I'm adding K to the negative one, which always yields 
            // me the appropriate positive remainder.
            if(remainder < 0) remainder += k;
            
            count += mp[remainder];
            mp[remainder]++;
            
        }
        
        return count;
        
        
        // USING RECURSION : Will give TLE
        // int count = 0;
        // check(nums, k, count, 0, n, 0);
        // return count;
    }
};