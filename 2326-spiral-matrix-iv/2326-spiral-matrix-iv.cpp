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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        ListNode* temp = head;
        int i = 0;
        int j = 0;
        int k = m-1;
        int l = n-1;
        
        while(i <= k && j <= l && temp) {
            
            for(int c=j ; c<=l && temp ; c++) {
                result[i][c] = temp->val;
                temp = temp->next;
            }
            if(!temp) break;
            i++;
            
            for(int r=i ; r<=k && temp ; r++) {
                result[r][l] = temp->val;
                temp = temp->next;
            }
            if(!temp) break;
            l--;
            
            if(j <= l && temp) {
                for(int c=l ; c>=j && temp ; c--) {
                    result[k][c] = temp->val;
                    temp = temp->next;
                }
                if(!temp) break;
                k--;
            }
            if(!temp) break;
            
            if(i <= k && temp) {
                for(int r=k ; r>=i && temp ; r--) {
                    result[r][j] = temp->val;
                    temp = temp->next;
                }
                if(!temp) break;
                j++;
            }
            if(!temp) break;
            
        }
        
        return result;
        
    }
};