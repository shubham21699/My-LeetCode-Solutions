class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        int n = piles.size();
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k--) {
            int x = pq.top();
            pq.pop();
            x = ceil(x / 2.0);
            pq.push(x);
        }
        
        int totalStones = 0;
        
        while(!pq.empty()) {
            totalStones += pq.top();
            pq.pop();
        }
        
        return totalStones;
    }
};