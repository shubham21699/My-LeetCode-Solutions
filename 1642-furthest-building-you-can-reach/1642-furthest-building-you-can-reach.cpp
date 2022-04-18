class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        if(n == 1) return 0;
        priority_queue<int> pq;
        
        int i = 0;
        
        for(i = 0 ; i < n-1 ; i++) {
            
            if(heights[i] >= heights[i+1]) continue;
            
            int d = heights[i+1] - heights[i];
            pq.push(d);
            bricks -= d;
            
            if(bricks >= 0) continue;
            if(ladders == 0) break;
            
            bricks += pq.top();
            pq.pop();
            ladders--;
        }
        
        return i;
    }
};