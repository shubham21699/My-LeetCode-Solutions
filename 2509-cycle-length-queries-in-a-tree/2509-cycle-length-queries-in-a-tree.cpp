class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        
        /* The left node has the value 2 * val, and
        The right node has the value 2 * val + 1.
        this means, no matter a node is left or right child, its parent is val / 2.
        
        For query x and y, we try to find their common ancestor.
        If x != y, we hadn't found yet. So we let the bigger node go up:
        if x > y, x = x / 2,
        if x < y, y = y / 2,
        and this take on step.
        We continue to do this until x == y.
        
        The cycle length is the number of steps plus 1.*/
        
        int q = queries.size();
        vector<int> result(q);
        
        for(int i=0 ; i<q ; i++) {
            
            int x = queries[i][0];
            int y = queries[i][1];
            int dist = 0;
            
            while(x != y) {
                if(x > y) x /= 2;
                else y /= 2;
                
                dist++;
            }
            
            result[i] = dist+1;
        }
        
        return result;
    }
};