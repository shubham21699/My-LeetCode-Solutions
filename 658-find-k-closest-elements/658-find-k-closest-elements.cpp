class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        if(n == 1 || k == n) return arr;
        if(arr[0] >= x) return vector<int>(arr.begin(), arr.begin()+k);
        
        priority_queue<int> pq;
        
        for(int i=n-1 ; i>=0 ; i--) {
            if(pq.size() >= k) {
                if(abs(arr[i] - x) < abs(pq.top() - x) || ((abs(arr[i] - x) == abs(pq.top() - x) && arr[i] < pq.top()))) {
                    pq.pop();
                    pq.push(arr[i]);
                }
                else continue;
            }
            else {
                pq.push(arr[i]);
            }
        }
                   
        vector<int> result;
                   
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
                   
        reverse(result.begin(), result.end());
        return result;
    }
};