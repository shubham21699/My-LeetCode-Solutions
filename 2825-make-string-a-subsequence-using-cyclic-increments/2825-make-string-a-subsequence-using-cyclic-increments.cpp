class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n = str1.length();
        int m = str2.length();
        int i = 0;
        int j = 0;
        
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                i++;
                j++;
            }
            else {
                char incCh = 'a' + (((str1[i]-'a')+1)%26);
                if(incCh == str2[j]) {
                    i++;
                    j++;
                }
                else i++;
            }
        }
        
        return j == m;
    }
};