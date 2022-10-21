class Solution {
public:
    int mod = pow(10, 9) + 7;
    
    void getPowers(vector<long long>& powers, long long n) {
        
        vector<long long> v;
        
        while (n > 0) {
            v.push_back(n % 2);
            n /= 2;
        }
        
        for(int i=0 ; i<v.size() ; i++) {
            if(v[i] == 1) powers.push_back(pow(2, i));
        }
        
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        int q = queries.size();
        vector<int> result(q);
        vector<long long> powers;
        
        getPowers(powers, n);
        
        for(int i=0 ; i<q ; i++) {
            
            int start = queries[i][0];
            int end = queries[i][1];
            long long prod = 1;
            
            while(start <= end) {
                prod *= powers[start];
                prod %= mod;
                start++;
            }

            result[i] = prod;
        }
        
        return result;
    }
};