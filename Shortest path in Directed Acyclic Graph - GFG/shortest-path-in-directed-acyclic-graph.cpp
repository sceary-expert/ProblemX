//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
  #define pii pair<int, int>
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>dist(N, INT_MAX);
        map<int, vector<pii>>mp;
        for(auto &edge : edges)
        {
            int i = edge[0], j = edge[1], d = edge[2];
            mp[i].push_back({j, d});
            // mp[j].push_back({i, d});
        }
        priority_queue<pii, vector<pii>, greater<pii>>q;
        q.push({0, 0});// distance from source, node
        dist[0] = 0;
        while(q.size())
        {
            auto tp = q.top(); q.pop();
            int d = tp.first; 
            int curr = tp.second;
            for(auto &ch : mp[curr])
            {
                int d2 = ch.second;
                int nx = ch.first;
                
                if(d2 + d < dist[nx])
                {
                    dist[nx] = d2 + d;
                    q.push({d2 + d, nx});
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(dist[i] == INT_MAX)dist[i] = -1;
        }
        return dist;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends