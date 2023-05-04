class Solution {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.length();
        queue<int> qr, qd;
        
        for(int i=0 ; i<n ; i++) {
            if(senate[i] == 'R') qr.push(i);
            else qd.push(i);
        }
        
        while(!qr.empty() && !qd.empty()) {
            
            int rIndex = qr.front();
            int dIndex = qd.front();
            qr.pop();
            qd.pop();
            
            if(rIndex < dIndex) qr.push(rIndex + n);
            else qd.push(dIndex + n);
            
        }
        
        return !qr.empty() ? "Radiant" : "Dire";
    }
};