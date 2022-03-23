class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        if(startValue >= target) return startValue - target;
        
        // If it is Odd:
        if(target & 1) return 1 + brokenCalc(startValue, target+1);
        
        // If it is Even:
        return 1 + brokenCalc(startValue, target/2);
    }
};