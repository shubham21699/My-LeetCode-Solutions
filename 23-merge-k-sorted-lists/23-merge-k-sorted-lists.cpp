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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n = lists.size();
        if(n == 0) return NULL;
        
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0 ; i<n ; i++) {
            ListNode* st = lists[i];
            while(st) {
                pq.push(st->val);
                st = st->next;
            }
        }
        
        while(!pq.empty()) {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        
        return result->next;
    }
};