class Solution {
public:
    void findInd(string stamp, string target, string res, int n, int m, vector<int> indices, vector<int>& resInd) {
        
        if(res == target) {
            resInd = indices;
            return;
        }
        
        for(int i=0 ; i<=m-n ; i++) {
            
            if(std::find(indices.begin(), indices.end(), i) == indices.end()) {
                string x = res.substr(i, n);

                res.replace(i, n, stamp);
                indices.push_back(i);

                findInd(stamp, target, res, n, m, indices, resInd);

                indices.pop_back();
                res.replace(i, n, x);
            }
        }
        
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        
        int n = stamp.length();
        int m = target.length();
        if(stamp == target) return { 0 };
        if(n == 1) {
            vector<int> v;
            for(int i=0 ; i<m ; i++) v.push_back(i);
            return v;
        }
        
        int tLen = m-n+1;
        int i, j;
        vector<int> resInd;
        bool tDiff = true, sDiff = false;
        
        while(tDiff) {
            
            for(i=0, tDiff=false ; i<tLen ; i++) {
                for(j=0, sDiff=false ; j<n ; j++) {
                    
                    if(target[i+j] == '?') continue;
                    else if(target[i+j] != stamp[j]) break;
                    else sDiff = true;
                    
                }
                
                if(j == n && sDiff) {
                    for(j=i, tDiff=true ; j<n+i ; j++) {
                        target[j] = '?';
                    }
                    
                    resInd.push_back(i);
                }
                
            }
            
        }
        
        for(int i=0 ; i<m ; i++) {
            if(target[i] != '?') return {};
        }
        
        reverse(resInd.begin(), resInd.end());
        return resInd;
        
        
//         // OR: Will give TLE
//         string res(m, '?');
        
//         vector<int> indices;
//         vector<int> resInd;
//         findInd(stamp, target, res, n, m, indices, resInd);
        
//         return resInd;
    }
};