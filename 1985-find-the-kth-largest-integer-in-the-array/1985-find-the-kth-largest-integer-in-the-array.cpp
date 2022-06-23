class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        sort(nums.begin(), nums.end(), [](string& a, string& b) {
            if(a.size() == b.size()) return a < b;
            return a.size() < b.size();
        });
        
        return nums[n-k];
    }
};