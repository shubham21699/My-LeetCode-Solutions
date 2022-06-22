class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int n = colors.length();
        if(n < 3) return false;
        if(n == 3) {
            if(colors[0] == colors[1] && colors[1] == colors[2] && colors[0] == 'A') return true;
            return false;
        }
        
        int countA = 0, countB = 0;
        for(int i=1 ; i<n-1 ; i++) {
            if(colors[i] == 'A' && colors[i] == colors[i-1] && colors[i] == colors[i+1]) 
                countA++;
            else if(colors[i] == 'B' && colors[i] == colors[i-1] && colors[i] == colors[i+1]) 
                countB++;
        }
        
        return countA > countB;
        
        
//         // OR:- Takes more time
//         unordered_set<int> sa, sb;
        
//         for(int i=1 ; i<n-1 ; i++) {
//             if(colors[i] == 'A' && colors[i] == colors[i-1] && colors[i] == colors[i+1]) 
//                 sa.insert(i);
//             else if(colors[i] == 'B' && colors[i] == colors[i-1] && colors[i] == colors[i+1]) 
//                 sb.insert(i);
//         }
        
//         int turn = 1;
        
//         while(!sa.empty() && !sb.empty()) {
//             if(turn%2 != 0) { // Alice turn
//                 sa.erase(sa.begin());
//             }
//             else { // Bob turn
//                 sb.erase(sb.begin());
//             }
            
//             turn++;
//         }
        
//         if(sa.empty()) return false;
//         return true;
    }
};