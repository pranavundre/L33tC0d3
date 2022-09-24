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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head, *q;
        while(p){
            n++;
            p = p->next;
        }
        n = n/k;
        int A[k];
        p = q = head;
        while(n){
            int i = 0;
            while(i != k){
                A[i] = p->val;
                i++;
                p = p->next;
            }
            i = 0;
            while(i != k){
                q->val = A[k-i-1];
                i++;
                q = q->next;
            }
            // cout<<n;
            // q = q->next;
            // p = p->next;
            n=n-1;
        }
        
        // while(head){
        //     cout<<head->val<<" ";
        //     head = head->next;
        // }
        
        return head;
    }
};