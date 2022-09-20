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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode *head = list2->val<list1->val ? list2 : list1;
        
        if(!(list1 && list2)){
            if(list1) return list1;
            else if(list2) return list2;
            else return NULL;
        }
        
        ListNode *head, *p = list1, *q = list2;
        
        if(list2->val<list1->val){
            head = list2;
            q = q->next;
        }else{
            head = list1;
            p = p->next;
        }
        ListNode *last = head;
        while(p && q){
            if(p->val < q->val){
                last->next = p;
                p = p->next;
            }else{
                last->next = q;
                q = q->next;
            }
            last = last->next;
        }
        if(p) last->next = p;
        if(q) last->next = q;
        return head;
    }
};