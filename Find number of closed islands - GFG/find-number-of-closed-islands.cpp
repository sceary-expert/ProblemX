//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool BFS(vector<vector<int>>&matrix, int i, int j, int N, int M)
    {
        if(i < 0 || j < 0 || i >= N || j >= M)return false;
        if(matrix[i][j] == 0)return true;
        matrix[i][j] = 0;
        bool f = true;
        for(auto &d : dir)
        {
            int x = i + d[0], y = j + d[1];
            f &= BFS(matrix, x, y, N, M);
            // if(f == false)return false;
        }
        return f;
        
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(matrix[i][j] == 1)
                {
                    bool f = BFS(matrix, i, j, N, M);
                    if(f == true)
                    {
                        // cout<<i<<" "<<j<<endl;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends