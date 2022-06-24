class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n = target.size();
        long sum = 0;
        priority_queue<int> pq;
        
        for(int i=0 ; i<n ; i++) {
            sum += target[i];
            pq.push(target[i]);
        }
        
        while(pq.top() != 1) {

            int num = pq.top();
            sum -= num;
            pq.pop();

            if(sum < 1 || num <= sum) return false;
            
            num %= sum;
            sum += num;
            pq.push(num ? num : sum);
        }
        
        return true;
    }
};