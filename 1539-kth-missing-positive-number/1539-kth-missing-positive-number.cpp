class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        int num = 1;
        
        while(k > 0) {
            
            if(st.find(num) == st.end()) {
                k--;
                if(k == 0) break;
            }
            
            num++;
        }
        
        return num;
    }
};