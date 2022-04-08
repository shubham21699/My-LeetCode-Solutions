class KthLargest {
    int kth = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        
        for(int i=0 ; i<nums.size() ; i++) {
            if(pq.size() == kth) {
                if(nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else pq.push(nums[i]);
        }
        
    }
    
    int add(int val) {
        
        if(pq.size() == kth) {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        else pq.push(val);
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */