//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node *h0 = new Node(-1);
        Node *h1 = new Node(-1);
        Node *h2 = new Node(-1);
        Node *it0 = h0;
        Node *it1 = h1;
        Node *it2 = h2;
        while(head)
        {
            int v = head -> data;
            if(v == 0)
            {
                h0 -> next = head;
                h0 = h0 -> next;
            }
            else if(v == 1)
            {
                h1 -> next = head;
                h1 = h1 -> next;
                
            }
            else{
                
                h2 -> next = head;
                h2 = h2 -> next;
            }
            head = head -> next;
        }
        if(!it1 -> next)
        {
            h0 -> next = it2 -> next;
            // cout<<"no 1"<<endl;
            
        }
        else{
        h0 -> next = it1 -> next;
        h1 -> next = it2 -> next;
        }
        h2 -> next = NULL;
        
        // h2 = NULL;
        auto ans = it0 -> next;
        
        return ans;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends