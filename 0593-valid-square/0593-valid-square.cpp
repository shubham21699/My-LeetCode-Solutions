class Solution {
public:
    double dist(vector<int>& point1, vector<int>& point2) {
        return sqrt(pow(point1[0] - point2[0], 2) + pow(point1[1] - point2[1], 2));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<vector<int>> points = {p1, p2, p3, p4};
        unordered_set<double> st;
        
        for(int i=0 ; i<4 ; i++) {
            for(int j=i+1 ; j<4 ; j++) {
                double d = dist(points[i], points[j]);
                if(d == 0) return false;
                st.insert(d);
            }
        }
        
        return st.size() == 2;
    }
};