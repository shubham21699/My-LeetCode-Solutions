class Solution {
public:
    int minimumSum(int n, int k) {
        
        unordered_set<int> st;
        int res = 0;
        int ele = 1;
        
        while(st.size() != n) {
            if(st.find(k - ele) == st.end()) {
                res += ele;
                st.insert(ele);
            }
            
            ele++;
        }
        
        return res;
    }
};