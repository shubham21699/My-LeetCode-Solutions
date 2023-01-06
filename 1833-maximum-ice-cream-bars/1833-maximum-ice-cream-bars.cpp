class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int n = costs.size();
        sort(costs.begin(), costs.end());
        
        if(costs[0] > coins) return 0;
        
        int count = 0;
        int cost = 0;
        int i = 0;
        
        while(i < n && cost+costs[i] <= coins) {
            cost += costs[i];
            count++;
            i++;
        }
        
        return count;
    }
};