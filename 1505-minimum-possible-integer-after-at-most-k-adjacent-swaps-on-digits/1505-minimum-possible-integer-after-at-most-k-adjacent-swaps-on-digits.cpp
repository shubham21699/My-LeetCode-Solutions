class Solution {
    bool isSmallest(string s) {
        for(int i=0 ; i<s.length()-1 ; i++) {
            if(s[i] > s[i+1]) return false;
        }
        
        return true;
    }
    
public:
    string minInteger(string num, int k) {
        
        int n = num.length();
        if(n == 1 || isSmallest(num)) return num;
        
        if(k == 1) {
            for(int i=0 ; i<n-1 ; i++) {
                if(num[i]-'0' > num[i+1]-'0') {
                    swap(num[i], num[i+1]);
                    break;
                }
            }
            
            return num;
        }
        
        string result = "";
        
        while(k > 0) {
            
            n = num.length();
            
            if(k >= n*(n-1)/2) {
                sort(num.begin(), num.end());
                return result + num;
            }
            
            int minInd = 0;
            
            for(int i=1 ; i<n && i<=k ; i++) {
                if(num[i] < num[minInd]) {
                    minInd = i;
                }
            }
            
            result += num[minInd];
            num = num.substr(0, minInd) + num.substr(minInd+1);
            k -= minInd;
            
        }
        
        result += num;
        return result;
    }
};