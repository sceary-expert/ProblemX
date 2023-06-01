//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    map<int, vector<int>>mp;
	    vector<int>endegree(V, 0);
	    for(int i = 0; i < V; i++)
	    {
	       // int u = adj[i][0], v = adj[i][1];
	        for(auto &it : adj[i])
	       // mp[u].push_back(v);
	        endegree[it]++;
	    }
// 	return {};
	queue<int>q;
	for(int i = 0; i < V; i++)
	{
	    if(endegree[i] == 0)
	    {
	        q.push(i);
	       // cout<<i<<" ";
	    }
	    
	}
	
	vector<int>answer;
// 	cout<<endl;
// 	return answer;
	while(q.size())
	{
	    int sz = q.size();
	    for(int i = 0; i < sz; i++)
	    {
	        auto e = q.front();
	        q.pop();
	        answer.push_back(e);
	        for(auto &ch : adj[e])
	        {
	            endegree[ch]--;
	            if(endegree[ch] == 0)
	            {
	                q.push(ch);
	            }
	        }
	    }
	}
	return answer;
  }
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends