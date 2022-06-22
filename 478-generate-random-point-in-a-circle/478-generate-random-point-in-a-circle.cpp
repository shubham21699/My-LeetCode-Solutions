class Solution {
public:
    double R, X, Y;
    
    double doubleRand() {
        return double(rand()) / double(RAND_MAX);
    }
    
    Solution(double radius, double x_center, double y_center) {
        
        R = radius;
        X = x_center;
        Y = y_center;
        srand(time(0));
        
    }
    
    vector<double> randPoint() {
        
        double len = sqrt(doubleRand()) * R;
        double deg = 2 * M_PI * doubleRand();
        
        return { X + len * cos(deg), Y + len * sin(deg) };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */