//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  
  
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        map<int, vector<vector<int>>>mp;      
        
        for(auto &flight : flights)
        {
            int u = flight[0], v = flight[1], w = flight[2];
            
            mp[u].push_back({v, w});
            // mp[v].push_back({u, w});
        }
        vector<int>dist(n + 1, INT_MAX);
        dist[k] = 0;
        queue<int>q;
        q.push(k);
        while(q.size() > 0)
        {
            q.pop();
            bool pos = false;
            // cout<<"K "<<k<<endl;
            for(auto &neighbor: mp[k])
            {
                int u = dist[k], v = neighbor[0], w = neighbor[1];
                if(u + w < dist[v])
                {
                    dist[v] = u + w;
                    pos = true;
                    q.push(v);
                    // cout<<"pushing "<<v<<endl;
                }
                
               
            }
            k = q.front();
            
            
            // if(pos == false)break;
        }
        int ans = INT_MIN;
        // for(auto it : dist)cout<<it<<" ";
        // cout<<endl;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends