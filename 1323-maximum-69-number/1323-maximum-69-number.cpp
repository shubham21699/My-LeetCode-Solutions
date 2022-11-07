class Solution {
public:
    int maximum69Number (int num) {
        
        int x = 0;
        while(num) {
            x = x*10 + (num % 10);
            num /= 10;
        }
        
        bool flag = false;
        
        while(x) {
            if(x % 10 == 6 && !flag) {
                num = num*10 + 9;
                flag = true;
            }
            else num = num*10 + (x % 10);
            
            x /= 10;
        }
        
        return num;
    }
};