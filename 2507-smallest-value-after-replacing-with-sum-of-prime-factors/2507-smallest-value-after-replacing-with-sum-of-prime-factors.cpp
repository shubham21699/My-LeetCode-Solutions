class Solution {
public:
    int getSumOfFactors(int n) {
        
        int divisor = 2;
        int factorsSum = 0;
        
        while(n > 1) {
            if(n % divisor == 0) {
                factorsSum += divisor;
                n /= divisor;
            }
            else divisor++;
        }
        
        return factorsSum;
    }
    
    int smallestValue(int n) {
        
        while(true) {
            
            int sum = getSumOfFactors(n);
            if(n == sum) break;
            
            n = sum;
        }
        
        return n;
    }
};