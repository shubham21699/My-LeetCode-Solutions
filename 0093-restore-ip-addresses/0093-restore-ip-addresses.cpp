class Solution {
public:
    void IPAddresses(string s, int index, int n, string x, int partitions, vector<string>& result) {
        
        if(index >= n && partitions == 4) result.push_back(x);
        if(partitions >= 4) return;
        
        for(int i=index ; i<index+3 && i<n ; i++) {
            string temp = s.substr(index, i-index+1);
            int value = stoi(temp);
            
            // No leading zero should be there.
            if(temp.length()>1 && temp[0] == '0') continue;
            
            // Integer range will be in between 0 and 255 inclusive.
            if(value >= 0 && value <= 255) {
                if(!x.empty()) temp = "." + temp;
                IPAddresses(s, i+1, n, x+temp, partitions+1, result);
            }
            
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.length();
        if(n < 4) return {};
        if(n == 4) {
            string x = to_string(s[0]-'0') + "." + to_string(s[1]-'0') + "." + to_string(s[2]-'0') + "." + to_string(s[3]-'0');
            return { x };
        }
        
        vector<string> result;
        string x = "";
        IPAddresses(s, 0, n, x, 0, result);
        return result;
    }
};