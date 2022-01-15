class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        int len = s.length();
        
        if(len == 1) return -1;
        if(len == 2) {
            if(s[0] < s[1]) {
                reverse(s.begin(), s.end());
                n = stoi(s);
                return n;
            }
            else return -1;
        }
        
        // One method to get next permutation
        int i = len-2;
        while(i>=0 && s[i] >= s[i+1]) {
            i--;
        }
        
        if(i == -1) return -1;
        
        reverse(s.begin()+i+1, s.end());
        
        for(int j=i+1 ; j<len ; j++) {
            if(s[j] > s[i]) {
                swap(s[j], s[i]);
                break;
            }
        }
        
        // OR : Another method to get next permutation is to use built-in function
        // next_permutation(s.begin(), s.end());
        
        int result = stoll(s);
        
        return (result <= n) ? -1 : result;
    }
};