class Solution {
public:
    double average(vector<int>& salary) {
        
        int n = salary.size();
        double sum = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i=0 ; i<n ; i++) {
            sum += salary[i];
            mini = min(mini, salary[i]);
            maxi = max(maxi, salary[i]);
        }
        
        return (sum - mini - maxi) / (n-2);
    }
};