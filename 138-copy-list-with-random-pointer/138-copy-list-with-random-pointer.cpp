/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *p = head;
        Node *newhead = new Node(head->val);
        // newhead->val = ;
        Node *q = newhead;
        p = p->next;
        while(p){
            Node *temp = new Node(p->val);
            q->next = temp;
            q = q->next;
            p = p->next;
        }
        q = newhead;
        p = head;
        int data;
        Node *a, *b;
        while(q){
            a = head;
            b = newhead;
            if(p->random){
                while(a!=p->random){
                    a = a->next;
                    b = b->next;
                }
                q->random = b;
            }
            else
                q->random = NULL;
            p = p->next;
            q = q->next;
        }
        return newhead;
    }
};