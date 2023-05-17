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
        int n = 1, res = INT_MIN;
        ListNode *node = head;
        while(node = node->next) n++;
        stack<int> stk;
        node = head;
        for(int i = 0; i < n; i++){
            if(i < n/2) stk.emplace(node->val);
            else{
                res = max(res, stk.top()+node->val);
                stk.pop();
            }
            node = node->next;
        }
        return res;
    }
};
