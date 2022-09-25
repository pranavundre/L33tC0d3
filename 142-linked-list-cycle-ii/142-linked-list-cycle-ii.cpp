/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p, *q;
        p = q = head;
        while(p && q && q->next){
            q = q->next->next;
            p = p->next;
            if(p == q){
                int n = 0;
                ListNode *r = head;
                while(p!=r){
                    p = p->next;
                    r = r->next;
                    n++;
                }
                return p;
            }
        }
        return NULL;
    }
};