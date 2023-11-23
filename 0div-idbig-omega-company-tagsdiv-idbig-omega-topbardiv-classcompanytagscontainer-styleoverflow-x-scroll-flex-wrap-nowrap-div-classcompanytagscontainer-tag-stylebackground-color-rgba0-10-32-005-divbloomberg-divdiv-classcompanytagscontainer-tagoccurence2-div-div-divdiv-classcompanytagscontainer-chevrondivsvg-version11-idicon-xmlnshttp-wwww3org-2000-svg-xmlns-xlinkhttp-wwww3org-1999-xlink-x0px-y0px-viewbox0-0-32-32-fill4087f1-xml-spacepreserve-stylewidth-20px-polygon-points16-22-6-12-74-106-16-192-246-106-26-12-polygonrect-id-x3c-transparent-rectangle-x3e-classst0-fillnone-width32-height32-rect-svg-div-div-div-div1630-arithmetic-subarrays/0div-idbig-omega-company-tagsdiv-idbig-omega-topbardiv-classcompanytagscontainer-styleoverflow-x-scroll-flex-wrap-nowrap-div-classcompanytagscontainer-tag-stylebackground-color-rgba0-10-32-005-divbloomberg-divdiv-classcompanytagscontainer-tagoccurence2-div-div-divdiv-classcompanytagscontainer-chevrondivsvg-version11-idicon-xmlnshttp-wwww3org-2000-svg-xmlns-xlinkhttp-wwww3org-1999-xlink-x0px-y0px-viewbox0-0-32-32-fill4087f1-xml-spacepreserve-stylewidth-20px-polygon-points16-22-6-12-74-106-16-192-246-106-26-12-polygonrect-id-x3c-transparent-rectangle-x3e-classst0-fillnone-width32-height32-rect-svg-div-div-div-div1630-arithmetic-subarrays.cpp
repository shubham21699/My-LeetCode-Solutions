class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        vector<bool> result(m, true);
        
        for(int i=0 ; i<m ; i++) {
            if(r[i] - l[i] <= 1) continue;
            
            vector<int> v(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(v.rbegin(), v.rend());
            int diff = v[1] - v[0];
            
            for(int j=2 ; j<v.size() ; j++) {
                if(v[j] - v[j-1] != diff) {
                    result[i] = false;
                    break;
                }
            }
        }
        
        return result;
    }
};