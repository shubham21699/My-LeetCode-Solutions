class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx == fx && sy == fy) return t != 1;
        
        int minDistReq = max(abs(fx - sx), abs(fy - sy));
        
        return t >= minDistReq;
    }
};