//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        stack<Node*>st1;
        stack<Node*>st2;
        while(head)
        {
            if(k)
            {
                st1.push(head);
                k--;
            }
            else{
                st2.push(head);
            }
            head = head -> next;
        }
        // cout<<st1.size()<<" "<<st2.size()<<endl;
        
        Node* ans = 
        NULL;
        Node* p =
        st1.top();
        st1.pop();
        ans  = p;
        
        while(st1.size())
        {
            // cout<<st1.top().data<<" ";
            p -> next = st1.top();
            st1.pop();
            p = p -> next;
        }
        
        while(st2.size())
        {
            // cout<<st2.top().data<<" ";
            p -> next = st2.top();
            st2.pop();
            p = p -> next;
        }
        p -> next = NULL;
        return ans;//ans -> next;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends