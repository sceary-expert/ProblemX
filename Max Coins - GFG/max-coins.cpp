//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end());
        vector<int>search_space(n);
        //{start_i, i}
        for(int i = 0; i < n; i++)
        {
            search_space[i] = ranges[i][0];
        }
        vector<int>SuffixMax(n);
        int currentMax = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            currentMax = max(currentMax, ranges[i][2]);
            SuffixMax[i] = currentMax;
        }
        int maxProfit = 0;
        for(int i = 0; i < n; i++)
        {
            int profit_i = ranges[i][2];
            // cout<<profit_i<<" ";
            int end_i = ranges[i][1];
            auto upperBound = upper_bound(search_space.begin() + i + 1, search_space.end(), end_i - 1);
            if(upperBound != search_space.end())
            {
                int next_i = upperBound - search_space.begin();
                // cout<<profit_i<<" "<<i<<" "<<next_i<<endl;
                if(next_i > i)profit_i += SuffixMax[next_i];
            }
            // cout<<profit_i<<endl;
            maxProfit = max(maxProfit, profit_i);
            
        }
        return maxProfit;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends