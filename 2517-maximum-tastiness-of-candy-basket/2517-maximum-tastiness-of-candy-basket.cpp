class Solution {
public:
    void findTastiness(vector<int>& price, vector<int> basket, unordered_set<int> st, int index, int n, int k, int& maxTastiness) {
        
        if(basket.size() == k) {
            
            int minDiff = INT_MAX;
            
            for(int i=0 ; i<k ; i++) {
                for(int j=i+1 ; j<k ; j++) {
                    minDiff = min(minDiff, abs(basket[j] - basket[i]));
                }
            }
            
            maxTastiness = max(maxTastiness, minDiff);
            return;
        }
        
        for(int i=index ; i<n ; i++) {
            if(st.find(price[i]) == st.end()) {
                basket.push_back(price[i]);
                st.insert(price[i]);
                
                findTastiness(price, basket, st, i+1, n, k, maxTastiness);
                
                basket.pop_back();
                st.erase(price[i]);
            }
        }
        
    }
    
    bool check(vector<int>& price, int k, int x) {
        
        int n = price.size();
        int count = 1;
        vector<int> basket;
        basket.push_back(price[0]);
        
        for(int i=1 ; i<n ; i++) {
            if(abs(price[i] - basket.back()) >= x) {
                basket.push_back(price[i]);
                count++;
            }
            
            if(count >= k) return true;
        }
        
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        
        int n = price.size();
        sort(price.begin(), price.end());
        
        int low = 0;
        int high = INT_MAX;
        int maxTastiness = 0;
        
        while(low <= high) {
            
            int mid = low + (high - low)/2;
            
            if(check(price, k, mid)) {
                maxTastiness = mid;
                low = mid+1;
            }
            else high = mid-1;
            
        }
        
        return maxTastiness;
        
//         // OR: Will give TLE
//         vector<int> basket;
//         unordered_set<int> st;
//         int maxTastiness = 0;
        
//         findTastiness(price, basket, st, 0, n, k, maxTastiness);
//         return maxTastiness;
    }
};