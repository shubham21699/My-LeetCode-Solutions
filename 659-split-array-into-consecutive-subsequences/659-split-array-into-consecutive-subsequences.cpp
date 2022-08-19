class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3) return false;
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        // Keep track of the number of sequences with size < 3
        int need_more = 0;
        
        for(auto num : nums) {
            
            if(mp[num-1].size() > 0) {
                
                // There exists a sequence that ends in num-1 
				// Append 'num' to this sequence
				// Remove the existing sequence
				// Add a new sequence ending in 'num' with size incremented by 1 
                
                int count = mp[num-1].top();
                mp[num-1].pop();
                mp[num].push(++count);
                
                if(count == 3) need_more--;
            }
            else {
                
                // There is no sequence that ends in num-1
				// Create a new sequence with size 1 that ends with 'num'
                need_more++;
                mp[num].push(1);
            }
            
        }
        
        return need_more == 0;
    }
};