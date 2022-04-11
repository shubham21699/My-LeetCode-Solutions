class MyHashSet {
    vector<int> st;
    
public:
    MyHashSet() {
        st.clear();
        st.resize(1000001, -1);
    }
    
    void add(int key) {
        st[key] = 1;
    }
    
    void remove(int key) {
        st[key] = -1;
    }
    
    bool contains(int key) {
        return st[key] == -1 ? false : true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */