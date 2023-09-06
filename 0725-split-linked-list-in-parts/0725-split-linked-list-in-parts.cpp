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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        if(k == 1) return { head };
        
        ListNode* temp = head;
        int len = 0;
        
        while(temp) {
            temp = temp->next;
            len++;
        }
        
        vector<ListNode*> result(k, NULL);
        int minListSize = max(1, len / k);
        int extra = len - (minListSize * k);
        int i = 0;
        
        while(head) {
            temp = head;
            
            int n = minListSize;
            
            while(temp && n>1) {
                temp = temp->next;
                n--;
            }
            
            if(extra > 0) {
                temp = temp->next;
                extra--;
            }
            
            ListNode* next = temp ? temp->next : NULL;
            if(temp) temp->next = NULL;
            
            result[i] = head;
            head = next;
            i++;
        }
        
        return result;
    }
};