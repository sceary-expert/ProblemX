//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    vector<vector<int>>DP;
    //Function to find the length of longest common subsequence in two strings.
    int FindLCS(string &s1, string &s2, int n1, int n2)
    {
        if(n1 < 1|| n2 < 1)return 0;
        if(DP[n1][n2] != -1)return DP[n1][n2];
        if(s1[n1 - 1] == s2[n2 - 1])return DP[n1][n2] = 1 + FindLCS(s1, s2, n1 - 1, n2 - 1);
        return DP[n1][n2] = max(FindLCS(s1, s2, n1 - 1, n2), FindLCS(s1, s2, n1, n2 - 1));
        
    }
    int lcs(int n, int m, string s1, string s2)
    {
        DP.resize(n + 1, vector<int>(m + 1, -1));
        int ans = FindLCS(s1, s2, n, m);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends