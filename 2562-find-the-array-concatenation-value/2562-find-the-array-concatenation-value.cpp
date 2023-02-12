class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
        int n = nums.size();
        long long result = 0;
        int i = 0;
        int j = n-1;
        
        while(i <= j) {
            
            if(i == j) result += nums[i];
            else {
                string x = to_string(nums[i]) + to_string(nums[j]);
                result += stoi(x);
            }
            
            i++;
            j--;
        }
        
        return result;
    }
};