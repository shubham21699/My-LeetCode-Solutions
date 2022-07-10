class SmallestInfiniteSet {
public:
    unordered_set<int> s;
    priority_queue<int, vector<int>, greater<int>> p;
    
    SmallestInfiniteSet() {
        for(int i=1 ; i<=1000 ; i++) {
            p.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest() {
        
        int x = p.top();
        s.erase(x);
        p.pop();
        return x;
    }
    
    void addBack(int num) {
        
        if(s.find(num) == s.end()) {
            s.insert(num);
            p.push(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */