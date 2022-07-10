class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        int water = 0;
        priority_queue<int> p;
        
        for(int i=0 ; i<3 ; i++) {
            if(amount[i] > 0) p.push(amount[i]);
        }
        
        while(p.size() > 1) {
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            a--;
            b--;
            if(a > 0) p.push(a);
            if(b > 0) p.push(b);
            water++;
        }
        
        if(!p.empty()) water += p.top();
        return water;
    }
};