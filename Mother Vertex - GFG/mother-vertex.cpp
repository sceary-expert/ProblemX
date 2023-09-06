//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void DFS(int root, vector<int> adj[], vector<bool>&vis)
    {
        
        vis[root] = true;
        for(auto &ch : adj[root])
        {
            // cout<<ch<<endl;
            // cout<<vis[ch]<<endl;
            if(vis[ch] == false)
            {
                DFS(ch, adj, vis);
            }
        }
        return;
        
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>vis(V, false);
	    int ans = -1;
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == false)
	        {
	            DFS(i, adj, vis);
	            ans = i;
	        }
	    }
	    vis = vector<bool>(V, false);
	    DFS(ans, adj, vis);
	    for(int i = 0; i < V; i++)if(vis[i] == false)return -1;
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends