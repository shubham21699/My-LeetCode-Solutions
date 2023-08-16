class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1 || k == 1) return nums;
        
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        
        for(int i=0 ; i<n ; i++) {
            
            pq.push({ nums[i], i });
            
            while(pq.top().second <= i-k) {
                pq.pop();
            }
            
            if(i >= k-1) result.push_back(pq.top().first);
        }
        
        return result;
        
//         // Monotonic Queue Approach using deque:
//         deque<int> d;
//         int index = 0;
        
//         for(int i=0 ; i<n ; i++) {
            
//             // Window range will be: [i - k + 1, i]
//             // So remove index that is out of window size range.
//             if(!d.empty() && d.front() <= i-k) {
//                 d.pop_front();
//             }
            
//             // Pop indexes such that index of largest elenent of particular window range
//             // will be at front of the queue.
//             while(!d.empty() && nums[i] >= nums[d.back()]) {
//                 d.pop_back();
//             }
            
//             d.push_back(i);
            
//             if(i >= k-1) result.push_back(nums[d.front()]);
            
//         }
        
//         return result;
    }
};