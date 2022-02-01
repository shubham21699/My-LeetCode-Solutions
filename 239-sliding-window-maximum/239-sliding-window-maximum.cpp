class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1 || k == 1) return nums;
        
        vector<int> result;
        // Monotonic Queue Approach using deque:
        deque<int> d;
        int index = 0;
        
        for(int i=0 ; i<n ; i++) {
            
            // Window range will be: [i - k + 1, i]
            // So remove index that is out of window size range.
            if(!d.empty() && d.front() <= i-k) {
                d.pop_front();
            }
            
            // Pop indexes such that index of largest elenent of particular window range
            // will be at front of the queue.
            while(!d.empty() && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }
            
            d.push_back(i);
            
            // Now push largest element of last window into resultant vector.
            if(i >= k-1) result.push_back(nums[d.front()]);
            
        }
        
        return result;
    }
};