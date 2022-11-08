class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pl, pr;
        long long cost = 0;
        
        for(int i=0 ; i<candidates ; i++) 
            pl.push(costs[i]);
        
        int i = candidates;
        int j = n-1;
        if(candidates > n-candidates) candidates = n-candidates;
        
        for(int k=0 ; k<candidates ; k++) 
            pr.push(costs[j--]);
        
        while(k--) {
            
            if(pl.empty() && !pr.empty()) {
                
                cost += pr.top();
                pr.pop();
                
                if(i <= j) {
                    pr.push(costs[j]);
                    j--;
                }
                
            }
            else if(!pl.empty() && pr.empty()) {
                
                cost += pl.top();
                pl.pop();
                
                if(i <= j) {
                    pl.push(costs[i]);
                    i++;
                }
                
            }
            else if(!pl.empty() && !pr.empty()) {
            
                int leftMin = pl.top();
                int rightMin = pr.top();

                if(leftMin <= rightMin) {
                    cost += leftMin;
                    pl.pop();
                    
                    if(i <= j) {
                        pl.push(costs[i]);
                        i++;
                    }
                    
                }
                else {
                    cost += rightMin;
                    pr.pop();
                    
                    if(i <= j) {
                        pr.push(costs[j]);
                        j--;
                    }
                    
                }
            }
            
        }
        
        return cost;
        
        
//         // OR: Will Give TLE
//         while(k--) {
            
//             int mini = INT_MAX;
//             int ind = -1;
            
//             for(int i=0 ; i<candidates && i<n ; i++) {
//                 if(costs[i] < mini) {
//                     mini = costs[i];
//                     ind = i;
//                 }
//             }
            
//             for(int i=n-1 ; i>=n-candidates && i>=0 ; i--) {
//                 if(costs[i] < mini) {
//                     mini = costs[i];
//                     ind = i;
//                 }
//             }
            
//             cost += mini;
//             costs.erase(costs.begin() + ind);
//             n--;
//         }
        
//         return cost;
    }
};