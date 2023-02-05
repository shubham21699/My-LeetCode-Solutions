class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        int m = banned.size();
        unordered_set<int> st(banned.begin(), banned.end());
        
        vector<int> v;
        for(int i=1 ; i<=n ; i++) {
            if(st.find(i) == st.end()) v.push_back(i);
        }
        
        int count = 0;
        int i = 0;
        int sum = 0;
        
        while(i < v.size() && sum + v[i] <= maxSum) {
            count++;
            sum += v[i];
            i++;
        }
        
        return count;
    }
};