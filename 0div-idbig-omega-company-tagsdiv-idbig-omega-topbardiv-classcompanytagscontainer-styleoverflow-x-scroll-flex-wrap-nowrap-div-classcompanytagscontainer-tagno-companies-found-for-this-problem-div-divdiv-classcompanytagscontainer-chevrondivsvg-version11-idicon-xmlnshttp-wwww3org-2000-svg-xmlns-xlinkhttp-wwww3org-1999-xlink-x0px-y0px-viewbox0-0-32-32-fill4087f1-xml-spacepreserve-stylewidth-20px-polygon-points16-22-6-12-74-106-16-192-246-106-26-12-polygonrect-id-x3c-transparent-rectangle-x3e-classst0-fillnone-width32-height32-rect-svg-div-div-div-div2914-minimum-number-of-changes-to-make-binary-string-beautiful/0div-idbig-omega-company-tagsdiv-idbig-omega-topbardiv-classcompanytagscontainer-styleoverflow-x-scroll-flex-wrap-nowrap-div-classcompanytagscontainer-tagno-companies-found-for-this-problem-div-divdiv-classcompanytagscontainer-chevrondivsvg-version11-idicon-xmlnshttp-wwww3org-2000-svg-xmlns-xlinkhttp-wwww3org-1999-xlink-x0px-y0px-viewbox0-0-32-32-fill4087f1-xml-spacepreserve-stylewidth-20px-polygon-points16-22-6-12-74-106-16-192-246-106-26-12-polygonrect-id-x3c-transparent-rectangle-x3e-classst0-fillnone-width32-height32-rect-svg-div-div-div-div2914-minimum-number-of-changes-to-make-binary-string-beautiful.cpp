class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();
        int count = 0;
        
        for(int i=0 ; i<n ; i+=2) {
            string x = s.substr(i, 2);
            if(x != "11" && x != "00") count++;
        }
        
        return count;
    }
};