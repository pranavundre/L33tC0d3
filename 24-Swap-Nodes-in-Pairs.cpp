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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        int n = 1;
        ListNode *node = head, *p = head, *q = head->next, *temp;
        while(node = node->next) n++;
        head = q;
        for(int i = 0; i < n/2; i++){
            if(i != 0) temp->next = q;
            p->next = q->next;
            q->next = p;
            temp = p;
            p = p->next;
            if(p) q = p->next;
        }
        return head;
    }
};

