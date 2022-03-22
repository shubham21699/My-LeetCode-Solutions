class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string result = "";
        if(n == 1) {
            result = 'a' + (k-1);
            return result;
        }
        
        int sum = k;
        
        for(int i=1 ; i<=n ; i++) {
            result += 'a';
            sum--;
        }
        
        if(sum == 0) return result;
        sum++; // Increase sum for last position because some bigger character will have to come here.
        
           
        for(int i=n-1 ; i>=0 && sum>0 ; i--) {
            if(sum >= 26) {
                sum += result[i]-'a'+1; // Increase value that is decremented earlier at this position.
                result[i] = 'z';
                sum -= 26;
            }
            else {
                result[i] = 'a' + (sum-1);
                break;
            }
        }
        
        return result;
    }
};