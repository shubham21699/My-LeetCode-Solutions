class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return to_string(nums[0]);
        
        vector<string> v(n);
        for(int i=0 ; i<n ; i++) v[i] = to_string(nums[i]);
        
        sort(v.begin(), v.end(), [] (string a, string b) {
            return a+b > b+a;
        });
        
        string result = "";
        
        for(int i=0 ; i<n ; i++) {
            result += v[i];
        }
        
        while(result[0] == '0' && result.length() > 1) {
            result.erase(0, 1);
        }
        
        return result;
    }
};