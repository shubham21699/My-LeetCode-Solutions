class Solution {
public:
    void findPrimeFactors(int val, unordered_set<int>& st) {
        
        int n = 2;
        
        while(val > 1) {
            if(val % n == 0) {
                while(val % n == 0) val /= n;
                st.insert(n);
            }
            else n++;
        }
        
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        unordered_set<int> st;
        
        for(int i=0 ; i<n ; i++) {
            if(mp.find(nums[i]) == mp.end()) {
                findPrimeFactors(nums[i], st);
                mp[nums[i]]++;
            }
        }
        
        return st.size();
    }
};