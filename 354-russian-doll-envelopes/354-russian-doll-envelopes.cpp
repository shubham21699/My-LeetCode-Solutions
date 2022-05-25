class Solution {
    int check(vector<vector<int> >& envelopes, int index, int n, vector<int> prev) {
        
        if(index >= n) return 0;
        if(envelopes[index][0] > prev[0] && envelopes[index][1] > prev[1]) return 1 + check(envelopes, index+1, n, envelopes[index]);
         
        return max(check(envelopes, index+1, n, prev), check(envelopes, index+1, n, envelopes[index]));
    }
    
public:
    static bool compare(vector<int>&a , vector<int>& b) {
      return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),compare);
         vector<int> dp;
         
        for(auto i:envelopes) {
            auto it=lower_bound(dp.begin(),dp.end(),i[1]);
            if(it==dp.end())
              dp.push_back(i[1]);
            else
              *it=i[1];
          }
          return dp.size();
        
//         int n = envelopes.size();
        
//         sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b) {
//             return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
//         });
        
//         return check(envelopes, 1, n, envelopes[0]) + 1;
        
    }
};