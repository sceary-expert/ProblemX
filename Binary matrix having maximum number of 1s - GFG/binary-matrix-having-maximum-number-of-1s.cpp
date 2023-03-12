//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int ans = -1, mn = N - 1;
        for(int i = 0; i < N; i++)
        {
            while( mn >= 0 && mat[i][mn] == 1 )
            {
                mn--;
                ans = i;
            }
            if(mn < 0)break;
        }
        if(ans == -1)
        {
            ans = 0;
            // mn = N;
        }
        return {ans, N - 1 - mn};
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends