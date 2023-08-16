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
    ListNode* partition(ListNode* head, int x) {
        ListNode *list1 = NULL, *list2 = NULL, *head1 = NULL, *head2 = NULL, *temp = head;
        if(head == NULL || head->next == NULL) return head;

        while(temp != NULL){
            if(temp->val < x){
                if(list1 == NULL){
                    list1 = temp;
                    head1 = temp;
                }
                else{
                    list1->next = temp;
                    list1 = temp;
                }
            }

            else{
                if(list2 == NULL){
                    list2 = temp;
                    head2 = temp;
                }
                else{
                    list2->next = temp;
                    list2 = temp;
                }
            }

            temp = temp->next;
        }

        if(list2) list2->next = NULL;
        if(list1 != NULL) list1->next = head2;
        else head1 = head2;

        return head1;
    }
};
