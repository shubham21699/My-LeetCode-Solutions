class Solution {
public:
    int nthUglyNumber(int n) {
        
        if(n <= 5) return n;
        
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        pq.push(1);
        
        while(n-- > 1) {
            
            long long int x = pq.top();
            pq.pop();
            
            if(x%2 == 0) {
                pq.push(x*2);
            }
            else if(x%3 == 0) {
                pq.push(x*2);
                pq.push(x*3);
            }
            else {
                pq.push(x*2);
                pq.push(x*3);
                pq.push(x*5);
            }
            
        }
        
        return pq.top();
        
        
//         // OR: Will give TLE
//         priority_queue<set<long long int>, vector<set<long long int>>, greater<set<long long int>>> pq;
//         set<long long int> s;
//         s.insert(1);
//         pq.push(s);
        
//         int uglyNo = 1;
        
//         for(int i=0 ; i<n ; i++) {
            
//             set<long long int> st = pq.top();
//             pq.pop();
            
//             long long int x = *st.begin();
//             uglyNo = x;
//             st.erase(st.begin());
            
//             st.insert(x*2);
//             st.insert(x*3);
//             st.insert(x*5);
//             pq.push(st);
            
//         }
        
//         return uglyNo;
    }
};