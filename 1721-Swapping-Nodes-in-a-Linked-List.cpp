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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front = head, *back = head;
        int k1 = k, swap;
        while(k1--) back = back->next;
        while(back){
            front = front->next;
            back = back->next;
        }
        back = head;
        while(--k) back = back->next;
        swap = back->val;
        back->val = front->val;
        front->val = swap;
        return head;
    }
};
