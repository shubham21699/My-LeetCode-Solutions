class Solution {
    // Max-Heapify
    void heapify(vector<int>& nums, int n, int index) {
        
        int largest = index; // Initialize largest as root
        int left_child = 2*index + 1; // Left child of root node
        int right_child = 2*index + 2; // Right child of root node
        
        // If left child is larger than root
        if(left_child < n && nums[left_child] > nums[largest]) {
            largest = left_child;
        }
        
        // If right child is larger than root
        if(right_child < n && nums[right_child] > nums[largest]) {
            largest = right_child;
        }
        
        // If largest is not the root of current subtree
        if(largest != index) {
            swap(nums[index], nums[largest]);
            
            // Recursively heapify the affected subtree
            heapify(nums, n, largest);
        }
        
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        // Using Heap Sort:-
        
        // Build heap by rearranging elements
        for(int i=n/2-1 ; i>=0 ; i--) {
            heapify(nums, n, i);
        }
        
        for(int i=n-1 ; i>0 ; i--) {
            // Move current root to end
            swap(nums[0], nums[i]);
            
            // Calling max-heapify on reduced heap
            heapify(nums, i, 0);
        }
        
        return nums;
        
        
//////////////// OR: Using Priority Queue ////////////
//         priority_queue<int, vector<int>, greater<int> > pq;
        
//         for(int i=0 ; i<n ; i++) {
//             pq.push(nums[i]);
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             nums[i] = pq.top();
//             pq.pop();
//         }
        
//         return nums;
        
//////////////// OR: ///////////////////////////////
        // sort(nums.begin(), nums.end());
        // return nums;
    }
};