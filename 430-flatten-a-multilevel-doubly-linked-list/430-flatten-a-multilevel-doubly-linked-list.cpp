/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(!head) return NULL;
        
        Node* temp = head;
        
        while(temp) {
            
            if(temp->child) {
                
                Node* next = temp->next;
                Node* itsChild = flatten(temp->child);
                temp->child = NULL;
                temp->next = itsChild;
                itsChild->prev = temp;
                
                Node* lastNode = itsChild;
                while(lastNode->next) lastNode = lastNode->next;
                
                lastNode->next = next;
                if(next) next->prev = lastNode;
                
            }
            
            temp = temp->next;
            
        }
        
        return head;
    }
};