class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0 ; i<n ; i++) pq.push(nums[i]);
        
        for(int i=0 ; i<n ; i++) {
            nums[i] = pq.top();
            pq.pop();
        }
        
        return nums;
        
        // OR
        // sort(nums.begin(), nums.end());
        // return nums;
    }
};