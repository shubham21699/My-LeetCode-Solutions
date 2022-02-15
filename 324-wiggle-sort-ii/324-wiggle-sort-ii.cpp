class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        
        vector<int> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());
        
        for(int i=n-1, j=0, k=(i/2)+1 ; i>=0 ; i--) {
            nums[i] = sorted[i&1 ? k++ : j++];
        }
        
    }
};