class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1) return "1";
        if(n == 2) return "11";
        string result = "11";
        
        for(int i=3 ; i<=n ; i++) {
            
            string x = "";
            int count = 1;
            
            for(int j=0 ; j<result.length() ; j++) {
                
                while(j+1<result.length() && result[j] == result[j+1]) {
                    count++;
                    j++;
                }
                x += count+'0';
                x += result[j];
                count = 1;
            }
            
            result = x;
        }
        
        return result;
    }
};