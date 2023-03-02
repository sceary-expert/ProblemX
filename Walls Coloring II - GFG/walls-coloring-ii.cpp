//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n = costs.size();
        if(n == 0)return 0;
        int k = costs[0].size();
        
        if( n != 1 && k == 1)return -1;
        auto DP = costs;
        
        for(int i = 1; i < n; i++)
        {
            auto v = DP[i - 1];
            sort(v.begin(), v.end());
            int mn = v[0], mn2 = v[1];
            for(int j = 0; j < k; j++)
            {
                if(DP[i - 1][j] == mn)DP[i][j] += mn2;
                else DP[i][j] += mn;
            }
        }
        // for(auto it : DP)
        // {
        //     for(auto i : it)cout<<i<<" ";
        //     cout<<endl;
        // }
        int ans = INT_MAX;
        for(int i = 0; i < k; i++)
        {
            ans = min(ans, DP[n - 1][i]);
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
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends