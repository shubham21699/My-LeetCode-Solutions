class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result;
        
        for(int i=n-1 ; i>=0 ; i--) {
            int x = nums[i];
            
            while(x) {
                result.push_back(x % 10);
                x /= 10;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};