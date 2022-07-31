class NumArray {
public:
    vector<int> v;
    int sum = 0;
    
    NumArray(vector<int>& nums) {
        
        v = nums;
        sum = accumulate(v.begin(), v.end(), 0);
    }
    
    void update(int index, int val) {
        
        int diff = val - v[index];
        sum += diff;
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        if(right - left < v.size()/2) return accumulate(v.begin()+left, v.begin()+right+1, 0);
        
        return sum - accumulate(v.begin(), v.begin()+left, 0) - accumulate(v.begin()+right+1, v.end(), 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */