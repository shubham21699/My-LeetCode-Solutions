class Solution {
public:
    /* We know that the <a/b> suffix is dependent on b and a goes till b, so if we can somehow try to find the
    optimal b, we should be able to get the answer.
    
    How to find optimal b:-
    We know that exact b does not matter, the only thing that matters is the length of b. Since the 
    length of the input string is 10^4, we know b would never have more than 4 digits in suffix.
    
    First we try to find out what would be length of b in the optimal answer and we try to build the string
    since a goes till b If we were able to find an optimal b then last a is your b since we are iterating from
    smallest length to largest length of b. */
    
    int getPossibleB(string message, int limit) {
        
        int n = message.length();
        
        for(int b = 1 ; b <= 4 ; b++) { // According to constraint b size will be upto 4 digits
            
            bool isPossible = true;
            int a = 1; // No. of partitions that can be made
            
            for(int j = 0 ; j < n ; ) {
                if(to_string(a).length() > b) {
                    isPossible = false;
                    break;
                }
                
                int suffixLen = 1 + to_string(a).length() + 1 + b + 1; // "<a/b>"
                int remainingLen = limit - suffixLen;
                
                j += remainingLen;
                a++;
            }
            
            if(isPossible) return a-1;
            
        }
        
        return -1;
    }
    
    vector<string> splitMessage(string message, int limit) {
        
        int b = getPossibleB(message, limit);
        if(b == -1) return {};
        
        int n = message.length();
        int a = 1;
        vector<string> result;
        
        for(int i = 0 ; i < n ; ) {
            
            string suffix = "<" + to_string(a) + "/" + to_string(b) + ">";
            int remainingLen = limit - suffix.length();
            string splitted = message.substr(i, remainingLen);
            
            result.push_back(splitted + suffix);
            i += remainingLen;
            a++;
        }
        
        return result;
    }
};