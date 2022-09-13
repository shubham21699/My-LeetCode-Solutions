class Solution {
public:
    string to8bit(int n) {
        
        string res;
        
        for(int i=7 ; i>=0 ; i--) {
            int k = n >> i;
            if(k & 1) res += "1";
            else res += "0";
        }
        
        return res;
    }
    
    bool validUtf8(vector<int>& data) {
        
        int n = data.size();
        vector<string> utf(n);
        
        for(int i=0 ; i<n ; i++) {
            utf[i] = to8bit(data[i]);
        }
        
        int i = 0;
        
        while(i < n) {
            
            string x = utf[i];
            
            // 1 bit 
            if(x.substr(0, 1) == "0") {
                i++;
            }
            
            // 2 bit
            else if(x.substr(0, 3) == "110") {
                if(utf[i+1].substr(0, 2) != "10") return false;
                i += 2;
            }
            
            // 3 bit
            else if(x.substr(0, 4) == "1110") {
                if(utf[i+1].substr(0, 2) != "10" || utf[i+2].substr(0, 2) != "10") return false;
                i += 3;
            }
            
            // 4 bit
            else if(x.substr(0, 5) == "11110") {
                if(utf[i+1].substr(0, 2) != "10" || utf[i+2].substr(0, 2) != "10" || utf[i+3].substr(0, 2) != "10") return false;
                i += 4;
            }
            
            else return false;
        }
        
        return true;
    }
};