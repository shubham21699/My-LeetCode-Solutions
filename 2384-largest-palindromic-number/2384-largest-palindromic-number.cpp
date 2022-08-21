class Solution {
public:
    string largestPalindromic(string num) {
        
        int n = num.length();
        unordered_map<int, int> mp;
        int countZeros = 0;
        
        for(int i=0 ; i<n ; i++) {
            mp[num[i]-'0']++;
        }
        
        if(mp.size() == 1 && num[0] == '0') return "0";
        
        int larOdd = -1;
        string res = "";
        
        for(int i=9 ; i>=0 ; i--) {
            
            if(mp[i] > 1) {
                
                int x = mp[i];
                if(x % 2 != 0) x--;
                x /= 2;
                
                char z = i+'0';
                
                while(x > 0) {
                    res += z;
                    x--;
                }
                
                if(mp[i] % 2 != 0) larOdd = max(larOdd, i);
                
            }
            else if(mp[i] == 1) larOdd = max(larOdd, i);
            
        }
        
        reverse(res.begin(), res.end());
        while(!res.empty() && res.back() == '0') res.pop_back(); // Removing Leading Zeros
        
        reverse(res.begin(), res.end());
        
        string x = res;
        reverse(x.begin(), x.end());
        
        if(larOdd != -1) res.push_back(larOdd+'0');
        res += x;
        
        return res;
    }
};