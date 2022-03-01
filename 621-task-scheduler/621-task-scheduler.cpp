class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int size = tasks.size();
        if(n == 0) return size;
        if(size == 1) return 1;
        unordered_map<char, int> mp;
        
        for(int i=0; i<size ; i++) {
            mp[tasks[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            pq.push(it->second);
        }
         
        int result = 0;
        
        while(!pq.empty()) {
            
            int top = pq.top();
            pq.pop();
            top--;
            
            vector<int> v;
            if(top > 0) v.push_back(top);
            
            int i = 0;
            result++;
            
            while(i < n && !pq.empty()) {
                if(pq.top() - 1 > 0) {
                    v.push_back(pq.top() - 1);
                }
                pq.pop();
                result++;
                i++;
            }
            
            if(i < n && v.size() > 0) result += (n - i);
            
            for(i=0 ; i<v.size() ; i++) {
                pq.push(v[i]);
            }
            
        }
        
        return result;
    }
};