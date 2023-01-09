class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        
        bool isBulky = false, isHeavy = false;
        
        if(length >= 10000 || width >= 10000 || height >= 10000 || ((long)length * (long)width * (long)height) >= 1000000000)
            isBulky = true;
        
        if(mass >= 100) isHeavy = true;;
        
        if(isBulky && isHeavy) return "Both";
        if(!isBulky && !isHeavy) return "Neither";
        if(isBulky && !isHeavy) return "Bulky";
        return "Heavy";
    }
};