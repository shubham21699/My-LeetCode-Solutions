class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count = 0;
        
        for(int num=max(11, low) ; num<=high ; num++) {
            
            string x = to_string(num);
            int len = x.length();
            if(len % 2 != 0) continue;
            
            int s1=0, s2=0;
            
            for(int i=0, j=len-1 ; i<j ; i++, j--) {
                s1 += x[i]-'0';
                s2 += x[j]-'0';
            }

            if(s1 == s2) count++;
        }
        
        return count;
    }
};