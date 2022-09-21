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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *p = head, *q = head, *r;
        
        if(!p->next){
            return NULL;
        }
        
        while(n != 0 && p->next){
            p = p->next;
            n--;
        }
        
        if(n==1)
            return head->next;
        
        while(p->next){
            q = q->next;
            p = p->next;
        }
        r = q->next;
        q->next = r->next;
        delete r;
        return head;
    }
};