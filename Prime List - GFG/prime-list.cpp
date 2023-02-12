//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:

    bool isPrime(int n){
        if (n<=1 || !(n%2)) return false;
        for (int i = 3; i < n/2; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    Node *primeList(Node *head){
        Node* p = head;
        while(p != NULL){
            bool replace = false;
            if(p->val<=2) {
                p->val = 2;
                replace = true;
            }
            int i = p->val;
            int j = p->val;
            while(!replace){
                if(isPrime(i)){ 
                    p->val=i;
                    replace = true;
                }else if(isPrime(j)){
                    p->val=j;
                    replace = true;
                }
                i--;
                j++;
            }
            p = p->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends