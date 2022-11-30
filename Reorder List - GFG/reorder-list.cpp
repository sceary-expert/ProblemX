//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
        stack<Node*>st;
        queue<Node*>q;
        int cnt = 0;
        Node* p = head;
        while(p)
        {
            cnt++;
            st.push(p);
            q.push(p);
            p = p -> next;
        }
       
        p = head;
        map<Node* , int>mp;
        mp[p]++;
        q.pop();
        //cout<<cnt<<endl; return;
        //cout<<head -> data<<" "<<cnt<<endl;
        // return;
        cnt--;
        
        while(cnt)//4
        {
            //if(mp[st.top()])break;
            p -> next = st.top();
            //mp[st.top()]++;
            //cout<<st.top() -> data<<" "<<cnt<<endl;
            st.pop();
            p = p -> next;
            cnt--;//3 1
            if(cnt)
            {
                if(mp[q.front()])break;
                p -> next = q.front();
                //mp[q.front()]++;
                //cout<<q.front() -> data<<" "<<cnt<<endl;
                p = p -> next;
                q.pop();
                cnt--;//2 0
            }
        }
        p -> next = NULL;
        // cout<<temp-> data<<endl;
        // cout<<temp -> next -> data<<endl;
        // p -> next = q.front();
        // head = p -> next;
        
    }
};



//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends