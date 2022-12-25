class Solution {
public:
    int mod = pow(10, 9) + 7;
    vector<long long> factorial;
    vector<long long> inverseFactorial;
    
    void findFactorial() {
        
        factorial = vector<long long>(100001, 1);
        inverseFactorial = vector<long long>(100001, 1);
        vector<long long> inverse(100001, 1);
        
        for(int i=2 ; i<=100000 ; i++) {
            factorial[i] = (factorial[i-1] * i) % mod;
            inverse[i] = mod - mod / i * inverse[mod % i] % mod;
            inverseFactorial[i] = (inverseFactorial[i-1] * inverse[i]) % mod;
        }
        
    }
    
    int numberOfDistinctPermutation(string s) {
        
        int n = s.length();
        vector<int> freq(26);
        
        for(int i=0 ; i<n ; i++) freq[s[i]-'a']++;
        
        long long fact = factorial[n];
        
        for(int i=0 ; i<26 ; i++) {
            if(freq[i] > 1) fact = (fact * inverseFactorial[freq[i]]) % mod; 
        }
        
        return fact;
    }
    
    int countAnagrams(string s) {
        
        int n = s.length();
        findFactorial();
        
        long long result = 1;
        string x = "";
        unordered_map<string, int> mp;
        
        for(int i=0 ; i<n ; i++) {
            if(s[i] == ' ') continue;
            
            x += s[i];
            
            if(i == n-1 || s[i+1] == ' ') {
                if(mp.find(x) == mp.end()) mp[x] = numberOfDistinctPermutation(x);
                result = (result * mp[x]) % mod;
                x = "";
            }
        }
        
        return result;
    }
};