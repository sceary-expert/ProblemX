//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    map<int, vector<int>>mp;
    vector<bool>light;
    void DFS(int root, int par, int n)
    {
        bool isLeaf = true;
        bool AllChildHasLight = true;
        for(auto &child : mp[root])
        {
            if(child == par)continue;
            isLeaf = false;
            DFS(child, root, n);
            if(light[child] == false)AllChildHasLight = false;
        }
        
        if(isLeaf)
        {
            
            if(light[par] == false)light[par] = true;
            return;
        }
        if(AllChildHasLight == false)
        {
            light[root] = true;
        }
    }
    int countVertex(int N, vector<vector<int>>edges){
        
        for(auto &it : edges)
        {
            
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
            
        }
        
        int ans = INT_MAX;
        int i = 1;
        // for(int i = 1; i <= N; i++)
        // {
            light.resize(N + 1, false);
            DFS(i, 0, N);
            int temp = 0;
            for(int i = 0; i <= N; i++)if(light[i])temp++;
            ans = min(ans, temp);
        // }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends