class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();
        if(n == 1) return stones[0];
        if(n == 2) return stones[0]==stones[1] ? 0 : abs(stones[0] - stones[1]);
            
        priority_queue<int> pq;
        
        for(int i=0 ; i<n ; i++) {
            pq.push(stones[i]);
        }
        
        while(pq.size() > 1) {
            
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x != y) pq.push(abs(y-x));
            
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};