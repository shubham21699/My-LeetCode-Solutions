class Solution {
public:
    int minDeletions(string s) {
        
        int n = s.length();
        unordered_map<char, int> freq;
        
        // Counting frequency of all characters.
        for(int i=0 ; i<n ; i++) {
            freq[s[i]]++;
        }
        
        // Store pairwise character with its frequency in decreasing order of their frequency.
        priority_queue<pair<int, char>> pq; 
        
        // Store count of each frequency.
        vector<int> frq(n+1, 0);
        
        // Store all the characters with multiple frequencies.
        unordered_set<char> st;
        
        // Stores and check characters with multiple frequencies.
        for(auto it=freq.begin() ; it!=freq.end() ; it++) {
            pq.push({ it->second, it->first });
            if(frq[it->second] > 0) st.insert(it->first);
            frq[it->second]++;
        }
        
        int countDeletions = 0; // No=umber of deletions we have to make to make string good.
        
        while(!pq.empty()) {
            
            int freqVal = pq.top().first;
            
            // If this is the character having frequency same as another character, then reduce 
            // it's frequency to that frequency which haven't been of any other character yet and 
            // count the deletions we have to made to make it's frequency unique.
            if(st.find(pq.top().second) != st.end()) {
                while(freqVal > 0 && frq[freqVal] != 0) {
                    freqVal--;
                    countDeletions++;
                }
                frq[freqVal]++;
            }
            
            pq.pop();
        }
        
        return countDeletions;
    }
};