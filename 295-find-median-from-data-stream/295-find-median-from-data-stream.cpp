class MedianFinder {
    // Will store half of low numbers, top of max-heap will be the highest among low numbers
    priority_queue<int> p; // Max-Heap
    
    // Will store half of high numbers, top of min-heap will be the lowest number among high numbers
    priority_queue<int, vector<int>, greater<int> > q; // Min-Heap
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        p.push(num);
        q.push(p.top());
        p.pop();
        
        if(q.size() > p.size()) {
            p.push(q.top());
            q.pop();
        }
    }
    
    double findMedian() {
        if(p.size() > q.size()) return p.top();
        return (p.top() + q.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */