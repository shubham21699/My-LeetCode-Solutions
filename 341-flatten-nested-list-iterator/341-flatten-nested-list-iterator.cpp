/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger* > nodes;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        int n = nestedList.size();
        
        for(int i=n-1 ; i>=0 ; i--) {
            nodes.push(&nestedList[i]);
        }
        
    }
    
    int next() {
        int result = nodes.top()->getInteger();
        nodes.pop();
        return result;
    }
    
    // Only flatten the Current Level untill we find an Integer.
    bool hasNext() {
        
        while(!nodes.empty()) {
            
            NestedInteger* current = nodes.top();
            
            // Ensure top most element is an Integer not Integer List
            if(current->isInteger()) {
                return true;
            }
            
            nodes.pop();
            
            // Decouple the Integer List abd add the decoupled element back to stack
            vector<NestedInteger> &adjacent = current->getList();
            
            for(int i=adjacent.size()-1 ; i>=0 ; i--) {
                nodes.push(&adjacent[i]);
            }
            
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */