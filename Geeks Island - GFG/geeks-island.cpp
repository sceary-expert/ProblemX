//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
int n, m;
vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isValid(int i, int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m)return false;
    return true;
}
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    n = N, m = M;
        // vector<vector<int>>grid;
        // grid.resize(N, vector<int>M(0));
        vector<vector<bool>>ind(N, vector<bool>(M, false));
        vector<vector<bool>>arab(N, vector<bool>(M, false));
        queue<vector<int>>qind;
        queue<vector<int>>qarab;
        
        for(int i = 0; i < M; i++)
        {
            ind[0][i] = true;
            arab[N - 1][i] = true;
            qind.push({0, i});
            qarab.push({N - 1, i});
            
        }
        for(int i = 0; i < N; i++)
        {
            ind[i][0] = true;
            arab[i][M - 1] = true;
            qind.push({i, 0});
            qarab.push({i, M - 1});
        }
        
        // for(int i = 0; i < N; i++)
        // {
        //     for(int j = 0; j < M; j++)
        //     {
        //         cout<<ind[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"----------------"<<endl;
        // for(int i = 0; i < N; i++)
        // {
        //     for(int j = 0; j < M; j++)
        //     {
        //         cout<<arab[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        while(qind.size())
        {
            auto top = qind.front();
            qind.pop();
            int i = top[0], j = top[1];
            for(auto &d : dir)
            {
                int ni = i + d[0], nj = j + d[1];
                if(isValid(ni, nj) && mat[i][j] <= mat[ni][nj] && ind[ni][nj] == false)
                {
                    ind[ni][nj] = true;
                    qind.push({ni, nj});
                }
                
            }
        }
        while(qarab.size())
        {
            auto top = qarab.front();
            qarab.pop();
            int i = top[0], j = top[1];
            for(auto &d : dir)
            {
                int ni = i + d[0], nj = j + d[1];
                if(isValid(ni, nj) && mat[i][j] <= mat[ni][nj] && arab[ni][nj] == false)
                {
                    arab[ni][nj] = true;
                    qarab.push({ni, nj});
                }
                
            }
        }
        
        // for(int i = 0; i < N; i++)
        // {
        //     for(int j = 0; j < M; j++)
        //     {
        //         cout<<ind[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"----------------"<<endl;
        // for(int i = 0; i < N; i++)
        // {
        //     for(int j = 0; j < M; j++)
        //     {
        //         cout<<arab[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(arab[i][j] && ind[i][j])ans++;
            }
        }
        return ans;
        
        
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends