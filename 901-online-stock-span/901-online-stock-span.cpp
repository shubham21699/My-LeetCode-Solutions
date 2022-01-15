class StockSpanner {
    stack<pair<int, int> > s;
    // OR
    // vector<int> v;
    
public:
    StockSpanner() {
        // v.clear();
    }
    
    int next(int price) {
        
        int count = 1;
        
        while(!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        
        s.push({ price, count });
        
//         OR :
//         for(int i=v.size()-1 ; i>=0 && v[i] <= price ; i--) {
//             count++;
//         }
        
//         v.push_back(price);
        
        return count;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */