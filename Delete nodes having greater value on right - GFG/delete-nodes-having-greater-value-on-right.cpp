//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    void CheckIfGreaterOnRightExist(Node *prev, Node *head, int & mxVal)
    {
        if(head == NULL)
        {
            return;
        }
        CheckIfGreaterOnRightExist(head, head -> next, mxVal);
        if(head -> data < mxVal)
        {
            Node* nx = head -> next;
            prev -> next = nx;
        }
        if(head -> data > mxVal)
        {
            mxVal = head -> data;
        }
        
    }
    Node *compute(Node *head)
    {
        Node* ans = new Node(0);
        ans -> next = head;
        int mxVal = INT_MIN;
        Node* prev = ans;
        CheckIfGreaterOnRightExist(prev, head, mxVal);
        return ans -> next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends