class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        int n = s.length();
        if(k == 1) return s.substr(0, 1);
        
        long long length = 0;
        int i = 0;
        
        while(length < k) {
            if(s[i] >= '2' && s[i] <= '9') length *= (s[i] - '0');
            else length++;
            
            i++;
        }
        
        for(int j=i-1 ; j>=0 ; j--) {
            
            if(s[j] >= '2' && s[j] <= '9') {
                length /= (s[j] - '0');
                k %= length;
            }
            else {
                if(k == 0 || k == length) return s.substr(j, 1);

                length--;
            }
        }

        return "";
    }
};