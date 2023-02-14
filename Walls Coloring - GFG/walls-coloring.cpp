//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        vector<vector<int>>DP = colors;
        for(int i = 1; i < N; i++)
        {
            DP[i][0] += min(DP[i - 1][1], DP[i - 1][2]);
            DP[i][1] += min(DP[i - 1][0], DP[i - 1][2]);
            DP[i][2] += min(DP[i - 1][1], DP[i - 1][0]);
        }
        return min(DP[N - 1][0], min(DP[N - 1][1], DP[N - 1][2]));
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends