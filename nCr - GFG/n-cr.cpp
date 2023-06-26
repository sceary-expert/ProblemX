//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = (int)(1e9 + 7);
    int FindNCR(int n, int r, vector<vector<int>>&DP)
    {
        if(n == 0|| r == 0 || n == r)return 1;
        if(r > n)return 0;
        if(DP[n][r] != -1)return DP[n][r];
        DP[n][r] = (FindNCR(n - 1, r, DP) + FindNCR(n - 1, r - 1, DP)) % mod;
        // cout<<n<<" "<< r<<" "<< DP[n][r]<<endl;
        return DP[n][r];
    }
    int nCr(int n, int r){
    vector<vector<int>>DP(n + 1, vector<int>(r + 1,  -1));
    DP[0][0] = 1;
    return FindNCR(n, r, DP);
    
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends