class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        if(color == image[sr][sc]) return image;
        
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        int currColor = image[sr][sc];
        image[sr][sc] = color;
        
        while(!q.empty()) {
            
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if(i+1<n && image[i+1][j] == currColor) {
                q.push({ i+1, j });
                image[i+1][j] = color;
            }
            if(j+1<m && image[i][j+1] == currColor) {
                q.push({ i, j+1 });
                image[i][j+1] = color;
            }
            if(i-1>=0 && image[i-1][j] == currColor) {
                q.push({ i-1, j });
                image[i-1][j] = color;
            }
            if(j-1>=0 && image[i][j-1] == currColor) {
                q.push({ i, j-1 });
                image[i][j-1] = color;
            }
            
            
        }
        
        return image;
    }
};