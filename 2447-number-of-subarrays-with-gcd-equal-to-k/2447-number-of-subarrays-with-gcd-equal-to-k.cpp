class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;
        
        for(int i=0 ; i<n ; i++) {
            int gcdOfSubArr = 0;
            for(int j=i ; j<n ; j++) {
                gcdOfSubArr = __gcd(gcdOfSubArr, nums[j]);
                if(gcdOfSubArr == k) count++;
                if(gcdOfSubArr < k) break;
            }
        }
        
        return count;
    }
};