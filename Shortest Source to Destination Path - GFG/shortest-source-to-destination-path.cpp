//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(vector<vector<int>>&A, int N, int M, int x, int y)
    {
        if(x < 0 || y < 0 || x >= N || y >= M || A[x][y] == 0)return false;
        return true;
    }
    vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0)return -1;
        int dist = 0;
        queue<pair<int, int>>q;
        q.push({0, 0});
        A[0][0] = 0;
        while(q.size())
        {
            int sz = q.size();
            for(int o = 0; o < sz; o++)
            {
                auto fr = q.front();
                q.pop();
                int i = fr.first, j = fr.second;
                if(i == X && j == Y)return dist;
                for(auto &d : dir)
                {
                    int x = i + d[0], y = j + d[1];
                    if(isValid(A, N, M, x, y))
                    {
                        q.push({x, y});
                        A[x][y] = 0;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends