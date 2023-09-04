//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        queue<pair<int, int>>q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] != 'O')continue;
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    q.push({i, j});
                }
            }
        }
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
                auto fr = q.front();
                q.pop();
                int i = fr.first, j = fr.second;
                mat[i][j] = 'M';
                for(auto &d : dir)
                {
                    int x = i + d[0], y = j + d[1];
                    if(x < n && y < m && x >= 0 && y >= 0 && mat[x][y] == 'O')q.push({x, y});
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] != 'M')mat[i][j] = 'X';
                else mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends