class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        
        if(num == 0) return true;
        
        int x = num;
        
        while(x >= num/2) {
        
            string n = to_string(x);
            string rev = n;
            reverse(rev.begin(), rev.end());
            
            int val = stoi(n) + stoi(rev);
            
            if(val == num) return true;
            x--;
        }
        
        return false;
    }
};