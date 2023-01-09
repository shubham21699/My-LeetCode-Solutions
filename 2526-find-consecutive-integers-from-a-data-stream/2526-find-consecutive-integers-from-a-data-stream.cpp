class DataStream {
public:
    vector<int> v;
    int val;
    int K;
    int count = 0;
    
    DataStream(int value, int k) {
        val = value;
        K = k;
    }
    
    bool consec(int num) {
        
        if(num == val) count++;
        else count = 0;
        v.push_back(num);
        
        return count >= K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */