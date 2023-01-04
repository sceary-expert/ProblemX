//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int maximum_profit(int n, vector<vector<int>> &inter) {
        // Write your code here.
        vector<vector<int>>intervals(n);
        for(int i = 0; i < n; i++)
        {
            int s = inter[i][0], e = inter[i][1], p = inter[i][2];
            intervals[i] = {e, s, p};
            
        }
        
        vector<int>DP(100005, 0);
        int maxProfit = 0;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; i++)
        {
            auto interval = intervals[i];
            int s = interval[1], e = interval[0], p = interval[2];
            
            DP[e] = max(DP[e], DP[s] + p);
            if(i < n - 1){
                int e2 = intervals[i + 1][0];
                for(int j = e + 1; j <= e2; j++)
                {
                    DP[j] = DP[e];
                }
            }
            maxProfit = max(maxProfit, DP[e]);
        }
        return maxProfit;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends