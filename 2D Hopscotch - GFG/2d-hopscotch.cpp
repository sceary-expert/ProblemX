//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>> oddDir = {{1, -1}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, 1}};
vector<vector<int>> evenDir = {{-1, 1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}};
vector<vector<bool>>visited;
bool isValid(int x, int  y, int n, int m){
    if(x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == true)return false;
    return true;
}
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        set<vector<int>>st;
        queue<vector<int>>q;
        visited.resize(n, vector<bool>(m, false));
        q.push({i, j});
        visited[i][j] = true;
        for(int o = 0; o <= ty; o++)
        {
            // cout<<"GHJK"<<endl;
            int sz = q.size();
            for(int szz = 0; szz < sz; szz++)
            {
                auto front = q.front();
                q.pop();
                int x = front[0], y = front[1];
                // cout<<"x : "<<x<<" y : "<<y<<endl;
                if(y % 2 == 1)
                {
                    for(auto &d : oddDir)
                    {
                        int newx = x + d[0], newy = y + d[1];
                        if(isValid(newx, newy, n, m))
                        {
                            // cout<<"new x : "<<newx<<" new y : "<<newy<<endl;
                            q.push({newx, newy});
                            visited[newx][newy] = true;
                        }
                    }
                }
                else{
                    for(auto &d : evenDir)
                    {
                        int newx = x + d[0], newy = y + d[1];
                        // cout<<newx<<" -- "<<newy<<endl;
                        if(isValid(newx, newy, n, m))
                        {
                            q.push({newx, newy});
                            visited[newx][newy] = true;
                        }
                    }
                    
                }
            }
            
            
        }
        while(q.size())
        {
            st.insert(q.front());
            q.pop();
        }
        int ans = 0;
        for(auto it : st)
        {
            // cout<<it[0]<<" "<<it[1]<<endl;
            ans += mat[it[0]][it[1]];
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends