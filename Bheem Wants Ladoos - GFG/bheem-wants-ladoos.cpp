//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    map<int, vector<int>>graph;
    void makeGraph(Node* root)
    {
        if(root == NULL)return;
        int rootValue = root -> data;
        if(root -> left)
        {
            int leftValue = root -> left -> data;
            graph[rootValue].push_back(leftValue);
            graph[leftValue].push_back(rootValue);
        }
        if(root -> right)
        {
            int rightValue = root -> right -> data;
            graph[rootValue].push_back(rightValue);
            graph[rightValue].push_back(rootValue);
        }
        makeGraph(root -> left);
        makeGraph(root -> right);
    }
    int TakeAllLadooInRange(int home, int k)
    {
        queue<int>q;
        q.push(home);
        int answer = home;
        map<int, int>visited;
        visited[home]++;
        while(k)
        {
            int currentQsize = q.size();
            
            for(int o = 0; o < currentQsize; o++)
            {
                int Home = q.front();
                q.pop();
                for(auto &neighbor : graph[Home])
                {
                    if(visited[neighbor])continue;
                    answer += neighbor;
                    visited[neighbor]++;
                    q.push(neighbor);
                }
            }
            k--;
        }
        return answer;
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        makeGraph(root);
        return TakeAllLadooInRange(home, k);
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends