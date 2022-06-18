/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();
        int i = 0;
        int j = n-1;
        int result = INT_MAX;
        int peak = 0;
        
        // Finding index of Peak Element
        while(i <= j) {
            
            int mid = i + (j - i)/2;
            
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
                i = mid+1;
                peak = mid+1;
            }
            else {
                j = mid-1;
            }
            
        }
        
        // 1st finding target on left side of Peak element.
        i = 0;
        j = peak;
        
        while(i <= j) {
            
            int mid = i + (j-i)/2;
            
            if(mountainArr.get(mid) == target) {
                result = mid;
                break;
            }
            else if(mountainArr.get(mid) > target) j = mid-1;
            else i = mid+1;
            
        }
        
        // If target found on left side, then return because it will be the minimum index target element.
        if(result != INT_MAX) return result;
        
        // If not found yet. then search for it in right side.
        i = peak;
        j = n-1;
        
        while(i <= j) {
            
            int mid = i + (j-i)/2;
            
            if(mountainArr.get(mid) == target) {
                result = mid;
                break;
            }
            else if(mountainArr.get(mid) > target) i = mid+1;
            else j = mid-1;
            
        }
        
        // If found, then return result else return -1.
        return result == INT_MAX ? -1 : result;
    }
};