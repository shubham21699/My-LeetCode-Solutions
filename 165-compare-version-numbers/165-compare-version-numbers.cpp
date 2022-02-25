class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        if(version1 == version2) return 0;
        int n = version1.length();
        int m = version2.length();
        
        int n1 = 0;
        int n2 = 0;
        int i = 0;
        int j = 0;
        
        while(i < n || j < m) {
            while(i<n && version1[i] >= '0' && version1[i] <= '9') {
                n1 = n1*10 + (version1[i] - '0');
                i++;
            }
            
            while(j<m && version2[j] >= '0' && version2[j] <= '9') {
                n2 = n2*10 + (version2[j] - '0');
                j++;
            }
            
            if(n1 < n2) return -1;
            if(n1 > n2) return 1;
            
            i++;
            j++;
            n1 = 0;
            n2 = 0;
        }
        
        return 0;
    }
};