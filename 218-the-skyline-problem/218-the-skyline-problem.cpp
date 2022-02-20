class Solution {
    vector<vector<int>> merge(vector<vector<int>> left, vector<vector<int>> right) {
        
        vector<vector<int> > ans;
        unordered_map<int, int> mp;
        
        int n = left.size();
        int m = right.size();
        int l = 0;
        int r = 0;
        int maxH = 0;
        int currentH = 0;
        int lefth = 0;
        int righth = 0;
        int x = -1;
        
        while(l < n && r < m) {
            
            if(left[l][0] < right[r][0]) {
                x = left[l][0];
                lefth = left[l][1];
                l++;
            }
            else {
                x = right[r][0];
                righth = right[r][1];
                r++;
            }
            
            maxH = max(lefth, righth);
            
            if(currentH != maxH) {
                currentH = maxH;
                mp[x] = max(mp[x], maxH);
            }
            
        }
        
        while(l < n) {
            mp[left[l][0]] = left[l][1];
            l++;
        }
        
        while(r < m) {
            mp[right[r][0]] = right[r][1];
            r++;
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++) {
            ans.push_back({ it->first, it->second });
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    vector<vector<int>> mergeSort(vector<vector<int>>& buildings, int start, int end) {
        
        vector<vector<int>> result;
        
        if(start > end) return result;
        if(start == end) {
            result.push_back({ buildings[start][0], buildings[start][2] });
            result.push_back({ buildings[start][1], 0 });
            return result;
        }
        
        int mid = start + (end - start)/2;
        vector<vector<int> > left = mergeSort(buildings, start, mid);
        vector<vector<int> > right = mergeSort(buildings, mid+1, end);
        result = merge(left, right);
        
        return result;
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        int n = buildings.size();
        if(n == 1) return {{ buildings[0][0], buildings[0][2] }, { buildings[0][1], 0 }};
        
        return mergeSort(buildings, 0, n-1);
    }
};