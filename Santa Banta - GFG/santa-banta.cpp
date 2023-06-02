//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<int>primes;
class Solution{
public:
    void precompute(){
        int r = 1500005;
        vector<bool>isPrime(r, true);
        isPrime[0] = false;
        isPrime[1] = false;
        primes.push_back(-1);
        for(int i = 0; i < r; i++)
        {
            if(isPrime[i] == false)continue;
            primes.push_back(i);
            for(int j = 2; j * i < r; j++)
            {
                isPrime[i * j] = false;
            }
        }
    }
    void helper(vector<vector<int>>& mp, vector<int>&connections, int i, int n,  vector<bool>&vis)
    {
        
        vis[i] = true;
        if(mp[i].size() == 0)
        {
            connections[i] = 0;
            return;
        }
        int ans = 1;
        queue<int>q;
        
        q.push(i);
        while(q.size())
        {
            int qf = q.front();
            q.pop();
            for(auto &ch : mp[qf])
            {
                if(vis[ch] == false)
                {
                    vis[ch] = true;
                    ans++;
                    q.push(ch);
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(vis[i] == true && connections[i] == -1)
            {
                connections[i] = ans;
            }
        }
        // return ans;
        
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // map<int, vector<int>>mp;
        // int u = 0;
        // for(auto &it : g)
        // {
        //     for(auto &v : it)
        //     {
        //         mp[u].push_back(v);
        //         mp[v].push_back(u);
        //     }
        //     u++;
        // }
        vector<bool>vis(n + 1, false);
        vector<int>connections(n + 1, -1);
        int max_connections = 0;
        for(int i = 1; i <= n; i++)
        {
            if(connections[i] == -1)
            {
                helper(g, connections, i, n, vis);
            }
            max_connections = max(max_connections, connections[i]);
        }
        return primes[max_connections];
        
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends