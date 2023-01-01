class Allocator {
public:
    vector<int> v;
    
    Allocator(int n) {
        v = vector<int>(n);
    }
    
    int allocate(int size, int mID) {
        
        int index = -1;
        int count = 0;
        
        for(int i=0 ; i<v.size() ; i++) {
            if(v[i] == 0) count++;
            else count = 0;
            
            if(count == size) {
                index = i-size+1;
                break;
            }
        }
        
        if(index == -1) return -1;
        
        for(int i=index ; i<index+size ; i++) v[i] = mID;
        
        return index;
    }
    
    int free(int mID) {
        
        int count = 0;
        
        for(int i=0 ; i<v.size() ; i++) {
            if(v[i] == mID) {
                v[i] = 0;
                count++;
            }
        }
        
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */