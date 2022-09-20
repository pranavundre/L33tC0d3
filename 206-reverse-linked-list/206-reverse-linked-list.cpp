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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        vector<int> A;
        while(p){
            A.push_back(p->val);
            p = p->next;
        }
        p = head;
        int i = A.size();
        while(p){
            p->val = A[i-1];
            i--;
            p = p->next;
        }
        return head;
    }
};