//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node* >v;
        string str = "";
        vector<bool>isAnagram;
        map<char, int>mp1;
        map<char, int>mp2;
        int cnt = 0;
        for(auto c : s)
        {
            mp1[c]++;
            if(mp1[c] == 1)cnt++;
        }
        while(head)
        {
            v.push_back(head);
            str += head -> data;
            head = head -> next;
            
        }
        int n = v.size();
        isAnagram.resize(n, false);
        queue<char>q;
        int curr = 0, sz = s.size();
        for(int i = 0; i < n; i++)
        {
            char c = str[i];
            q.push(c);
            mp2[c]++;
            if(mp2[c] == mp1[c])
            {
                curr++;    
            }
            while(q.size() > sz)
            {
                auto fr = q.front();
                q.pop();
                if(mp2[fr] == mp1[fr])curr--;
                mp2[fr]--;
            }
            if(cnt == curr)
            {
                isAnagram[i + 1 - sz] = true;  
                // v[i] -> next = NULL;
            }
        }
        vector<Node*>ans;
        // for(auto it : v)
        // {
        //     cout<<it -> data<<" ";
        // }
        // cout<<endl;
        // cout<<v.size()<<" " <<n<<endl;
        for(int i = 0; i < n; i++)
        {
            // cout<<isAnagram[i]<<" ";
            if(isAnagram[i] == true)
            {
                ans.push_back(v[i]);
                v[i + sz - 1] -> next = NULL;
                i += sz - 1;
            }
        }
        // cout<<endl;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends