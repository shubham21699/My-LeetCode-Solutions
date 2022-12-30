/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* temp = head;
        vector<int> v;
        
        while(temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = v.size();
        for(int i=n-2 ; i>=0 ; i--) {
            v[i] = max(v[i], v[i+1]);
        }
        
        temp = head;
        ListNode* prev = head;
        int i = 0;
        
        while(temp->next) {
            if(temp->val < v[i]) {
                if(head->val == temp->val) {
                    head = temp->next;
                    prev = head;
                    temp = temp->next;
                }
                else {
                    prev->next = temp->next;
                    temp = prev->next;
                }
            }
            else {
                prev = temp;
                temp = temp->next;
            }
            
            i++;
        }
        
        return head;
    }
};