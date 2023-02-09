class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        int n = basket1.size();
        map<int, int> freq;
        
        for(int i=0 ; i<n ; i++) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }
        
        vector<int> eleToSwap;
        
        for(auto it=freq.begin() ; it!=freq.end() ; it++) {
            if(it->second % 2 != 0) return -1;
            
            for(int i=0 ; i<abs(it->second)/2 ; i++) {
                eleToSwap.push_back(it->first);
            }
        }
        
        long long cost = 0;
        
        for(int i=0 ; i<eleToSwap.size()/2 ; i++) {
            cost += min(eleToSwap[i], freq.begin()->first * 2);
        }
        
        return cost;
    }
};