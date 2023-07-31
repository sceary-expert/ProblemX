//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        map<int, set<int>>v;
        for(int i = 0; i < adj -> size(); i++)
        {
            for(auto &ch : adj[i])
            {
                v[i].insert(ch);
                v[ch].insert(i);
            }
        }
        vector<int>ans;
        queue<int>q;
        q.push(0);
        map<int, bool>mp;
        mp[0] = true;
        while(q.size())
        {
            auto fr = q.front(); q.pop();
            ans.push_back(fr);
            // mp[fr] = true;
            for(auto &ch : adj[fr])
            {
                if(!mp[ch])
                {
                    q.push(ch);
                    mp[ch] = true;
                }
                // else mp[ch] = true;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends