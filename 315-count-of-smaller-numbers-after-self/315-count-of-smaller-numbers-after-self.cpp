class Node {
    public:
    int val;
    int count;
    Node* left;
    Node* right;
    
    Node(int num1, int num2) {
        this->val = num1;
        this->count = num2;
        this->left = this->right = NULL;
    }
    
};

class Solution {
    // Function to add Node and find smaller elenents count on its right side.
    int addNode(Node* &root, int value, int countSmallerToRight) {
        
        // While inserting the elements to the BST, we can compute the number of elements 
        // which are lesser elements simply by computing the sum of frequency of the element 
        // and the number of elements to the left side of current node, if we are moving 
        // to right side of the current node. 
        // Once we place an element in it’s correct position, we can return it’s this sum value.
        
        // Base Case
        if(!root) {
            root = new Node(value, 0);
            return countSmallerToRight;
        }
        
        if(root->val < value) {
            return root->count + addNode(root->right, value, countSmallerToRight + 1);
        }
        else {
            root->count++;
            return addNode(root->left, value, countSmallerToRight);
        }
        
    }
    
    void merge(vector<int>& nums, vector<int>& indices, vector<int>& result, int left, int mid, int right) {
        
        vector<int> leftArray(mid-left+1, 0);
        vector<int> rightArray(right-mid, 0);
        
        int n = leftArray.size();
        int m = rightArray.size();
        
        for(int i=0 ; i<n ; i++) {
            leftArray[i] = indices[left + i];
        }
        
        for(int j=0 ; j<m ; j++) {
            rightArray[j] = indices[mid + 1 + j];
        }
        
        int i = 0;
        int j = 0;
        int k = left;
        int rightCount = 0;
        
        while(i < n && j < m) {
            
            if(nums[leftArray[i]] <= nums[rightArray[j]]) {
                indices[k] = leftArray[i];
                result[leftArray[i]] += rightCount; 
                i++;
            }
            else {
                indices[k] = rightArray[j];
                j++;
                rightCount++;
            }
            
            k++;
        }
        
        while(i < n) {
            indices[k] = leftArray[i];
            result[leftArray[i]] += rightCount;
            i++;
            k++;
        }
        
        while(j < m) {
            indices[k] = rightArray[j];
            j++;
            k++;
        }
        
    }
    
    void merge_sort(vector<int>& nums, vector<int>& indices, vector<int>& result, int left, int right) {
        
        if(left < right) {
            
            int mid = left + (right - left)/2;
            
            merge_sort(nums, indices, result, left, mid);
            merge_sort(nums, indices, result, mid+1, right);
            merge(nums, indices, result, left, mid, right);
            
        }
        
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n, 0);
        
        // Using merge sort Approach:
        vector<int> indices(n, 0);
        for(int i=0 ; i<n ; i++) {
            indices[i] = i;
        }
        
        merge_sort(nums, indices, result, 0, n-1);
        
        return result;
        
//         OR:
//         set<int> s;
        
//         for(int i=n-1 ; i>=0 ; i--) {
//             s.insert(nums[i]);
//             auto it = s.lower_bound(nums[i]);
//             result[i] = distance(s.begin(), it);
//         }
        
//         return result;
        
//         OR: O(nLogn)
//         if(n == 1) return result;
//         if(n == 2) {
//             if(nums[0] > nums[1]) result[0] = 1;
//             return result;
//         }
        
//         Node* root = NULL;
        
//         // We traverse the input array from the ending to the beginning and add the elements into the BST.
//         for(int i=n-1 ; i>=0 ; i--) {
//             result[i] = addNode(root, nums[i], 0);
//         }
        
//         return result;
    }
};