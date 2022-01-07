class Solution {
    int count = 0;
    
    void merge(vector<int>& nums, int start, int mid, int end) {
        
        int left = start;
        int right = mid+1;
        
        while(left <= mid && right <= end) {
            if((long)nums[left] > (long) 2 * nums[right]) {
                count += (mid - left + 1);
                right++;
            }
            else left++;
        }
        
        sort(nums.begin()+start, nums.begin()+end+1);
        
    }
    
    void mergeSort(vector<int>& nums, int start, int end) {
        
        if(start < end) {
            int mid = (start + end) / 2;
            
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, start, mid, end);
        }
        
    }
    
public:
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        count = 0;
        mergeSort(nums, 0, n-1);
        
        return count;
        
    }
};