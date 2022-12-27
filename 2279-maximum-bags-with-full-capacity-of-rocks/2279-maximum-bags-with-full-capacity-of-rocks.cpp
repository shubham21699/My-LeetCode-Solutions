class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int n = capacity.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0 ; i<n ; i++) pq.push({ capacity[i] - rocks[i] });
        
        int countBags = 0;
        
        while(!pq.empty() && additionalRocks >= pq.top()) {
            additionalRocks -= pq.top();
            pq.pop();
            countBags++;
        } 
        
        return countBags;
    }
};