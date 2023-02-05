class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n = gifts.size();
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long count = 0;
        
        for(int i=0 ; i<k ; i++) {
            if(pq.top() == 1) break;
            
            int x = pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        
        while(!pq.empty()) {
            count += pq.top();
            pq.pop();
        }
        
        return count;
    }
};