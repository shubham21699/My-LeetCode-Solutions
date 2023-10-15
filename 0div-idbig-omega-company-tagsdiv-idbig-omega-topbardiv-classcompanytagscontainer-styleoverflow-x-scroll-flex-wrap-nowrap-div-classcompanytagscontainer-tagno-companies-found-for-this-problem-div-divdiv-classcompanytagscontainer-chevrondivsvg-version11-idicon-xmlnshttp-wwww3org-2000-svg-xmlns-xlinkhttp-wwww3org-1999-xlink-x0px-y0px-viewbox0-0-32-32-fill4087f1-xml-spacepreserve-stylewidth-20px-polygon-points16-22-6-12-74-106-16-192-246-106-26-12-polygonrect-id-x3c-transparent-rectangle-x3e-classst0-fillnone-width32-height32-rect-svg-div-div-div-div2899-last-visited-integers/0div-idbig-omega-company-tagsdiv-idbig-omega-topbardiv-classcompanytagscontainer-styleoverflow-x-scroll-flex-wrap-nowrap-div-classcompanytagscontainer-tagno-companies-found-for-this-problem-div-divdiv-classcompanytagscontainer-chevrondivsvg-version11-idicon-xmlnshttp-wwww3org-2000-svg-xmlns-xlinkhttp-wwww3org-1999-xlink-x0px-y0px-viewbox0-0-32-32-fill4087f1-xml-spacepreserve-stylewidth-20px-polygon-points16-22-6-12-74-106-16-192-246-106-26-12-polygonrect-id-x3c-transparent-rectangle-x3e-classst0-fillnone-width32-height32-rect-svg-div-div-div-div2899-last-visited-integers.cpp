class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        
        int n = words.size();
        vector<int> result, v;
        int prevCount = 0;
        
        for(int i=0 ; i<n ; i++) {
            if(words[i] != "prev") {
                v.push_back(stoi(words[i]));
                prevCount = 0;
            }
            else {
                prevCount++;
                if(prevCount > v.size()) result.push_back(-1);
                else {
                    result.push_back(v[v.size() - prevCount]);
                }
            }
        }
        
        return result;
    }
};