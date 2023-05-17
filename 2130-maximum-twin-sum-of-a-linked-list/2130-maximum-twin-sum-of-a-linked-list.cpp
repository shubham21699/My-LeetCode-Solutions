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
    int pairSum(ListNode* head) {
        
        int len = 0;
        stack<int> st;
        ListNode* temp = head;
        
        while(temp) {
            st.push(temp->val);
            len++;
            temp = temp->next;
        }
        
        temp = head;
        len /= 2;
        int result = 0;
        
        while(len > 0) {
            result = max(result, temp->val + st.top());
            st.pop();
            len--;
            temp = temp->next;
        }
        
        return result;
    }
};