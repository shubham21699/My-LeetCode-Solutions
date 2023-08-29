class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        
        unordered_set<int> st;
        long long sum = 0;
        int val = 1;
        
        while(st.size() != n) {
            if(st.find(target - val) == st.end()) {
                sum += val;
                st.insert(val);
            }
            
            val++;
        }
        
        return sum;
    }
};