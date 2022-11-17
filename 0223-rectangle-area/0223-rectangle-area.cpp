class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int area1 = abs(ax2 - ax1) * abs(ay2 - ay1);
        int area2 = abs(bx2 - bx1) * abs(by2 - by1);
        
        if(ax2 <= bx1 || ax1 >= bx2 || ay2 <= by1 || ay1 >= by2) return area1+ area2;
        
        int overlappedArea = (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
        return area1 + area2 - overlappedArea;
    }
};