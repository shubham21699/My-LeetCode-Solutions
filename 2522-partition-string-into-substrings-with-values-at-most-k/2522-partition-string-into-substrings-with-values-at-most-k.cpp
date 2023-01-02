class Solution {
public:
    int minimumPartition(string s, int k) {
        
        int n = s.length();
        int count = 0;
        
        for(int i=0 ; i<n ;) {
            
            if(s[i]-'0' > k) return -1;
            
            long long num = 0;
            int j = i;
            
            while(j < n && num*10 + (s[j]-'0') <= k) {     
                num = num*10 + (s[j]-'0');
                j++;
            }
            
            count++;
            i = j;
        }
        
        return count;
    }
};