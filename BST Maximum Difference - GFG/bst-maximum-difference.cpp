//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
#define d(x) cout<<#x<<" " <<x<<endl;
    int ans, tillTarget, tillLeaf, targetNodeVal;
    Node *Target;
    void LeafFromTarget(Node *curr, int sum)
    {
        if(curr == NULL)
        {
            ans = INT_MAX;
        }
        if(ans == INT_MAX)return;
        sum += curr -> data;
        if(curr -> left == NULL && curr -> right == NULL)
        {
            // d(sum);
            sum -= targetNodeVal;
            int temp =  tillTarget - sum;
            ans = max(ans, temp);
            return;
        }
        
        if(curr -> left)LeafFromTarget(curr -> left, sum);
        if(curr -> right)LeafFromTarget(curr -> right, sum);
        // d(curr -> data);
        // cout<<sum<<endl;
        
    }
    void Travarse(Node *root, int target)
    {
        if(root == NULL)
        {
            tillTarget = -1;
            return;
        }
        int rootData = root -> data;
        if(rootData == target)
        {
            Target = root;
            return;
        }
        tillTarget += rootData;
        if(rootData < target)
        {
            Travarse(root -> right, target);
        }
        else Travarse(root -> left, target);
        
    }
    int maxDifferenceBST(Node *root,int target){
        // if(root -> data == target)return -1;
        targetNodeVal = target;
        ans = INT_MIN;
        tillTarget = 0;
        tillLeaf = 0;
        Travarse(root, target);
        if(tillTarget == -1)return -1;
        // d(tillTarget);
        LeafFromTarget(Target, 0);
        if(ans == INT_MAX)return -1;
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends