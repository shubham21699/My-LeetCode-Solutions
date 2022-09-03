class Solution {
public:
    void find(int n, int k, int num, int prevDigit, int count, vector<int>& result) {
        
        if(count == n) {
            result.push_back(num);
            return;
        }
        
        if(prevDigit - k >= 0 && k!=0) find(n, k, num*10 + (prevDigit-k), prevDigit-k, count+1, result);
        if(prevDigit + k < 10) find(n, k, num*10 + (prevDigit+k), prevDigit+k, count+1, result);
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> result;
        
        for(int i=1 ; i<=9 ; i++) {
            find(n, k, i, i, 1, result);
        }
        
        return result;
    }
};