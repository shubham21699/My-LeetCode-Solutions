class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        int n = ops.size();
        if(n == 1) return stoi(ops[0]);
        
        vector<int> res;
        
        for(int i=0 ; i<n ; i++) {
            if(ops[i] == "C") res.pop_back();
            else if(ops[i] == "D") res.push_back(res.back()*2);
            else if(ops[i] == "+") res.push_back(res.back() + res[res.size()-2]);
            else res.push_back(stoi(ops[i]));
        }
        
        return accumulate(res.begin(), res.end(), 0);
    }
};