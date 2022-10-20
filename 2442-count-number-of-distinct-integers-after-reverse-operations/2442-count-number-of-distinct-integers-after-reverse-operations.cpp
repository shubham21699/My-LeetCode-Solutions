class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        
        for(int i=0 ; i<n ; i++) {
            
            int num = nums[i];
            int revNum = 0;
            
            while(num) {
                revNum = revNum*10 + (num%10);
                num /= 10;
            }
            
            st.insert(revNum);
        }
        
        return st.size();
    }
};