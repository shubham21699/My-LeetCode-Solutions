class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1) return arr;
        
        sort(arr.begin(), arr.end(), [](const int& n1, const int& n2) {
            
            int b1 = 0, b2 = 0;
            int a1 = n1;
            int a2 = n2;
        
            while(a1) {
                if(a1 & 1) b1++;
                a1 >>= 1;
            }
            
            while(a2) {
                if(a2 & 1) b2++;
                a2 >>= 1;
            }

            if(b1 == b2) return n1 < n2;
            return b1 < b2;
        });
        
        return arr;
    }
};