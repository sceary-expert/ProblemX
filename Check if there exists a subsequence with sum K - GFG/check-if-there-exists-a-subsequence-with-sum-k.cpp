//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool solve(vector<int>& arr,int index,int k,int n, vector<vector<int>>&DP)
    {
        if(k == 0)return true;
        if(k < 0)return false;
        if(index>=n)
        {
            // ans.push_back(output);
            if(k == 0)
            {
                return true;
            }
            return false;
        }
        if(DP[index][k] != -1)return DP[index][k] == 1;
        //excluding case
        bool exclude = solve(arr,index+1,k,n, DP);
        //inclusnig case
        int element=arr[index];
        // output.push_back(element);
        // s+=arr[index];
        // k -= element;
        bool include = solve(arr,index+1, k - element,n, DP);
        // bool f = (f1|f2);
        if (exclude || include) {
            DP[index][k] = 1;
        } else {
            DP[index][k] = 0;
        }
        return DP[index][k] == 1;
        
    }
    
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<vector<int>>DP(n + 1, vector<int>(k + 1, -1));
        // Code here
        // vector<vector<int>> ans;
        // vector<int> output;
        int index=0;
        // int sum=0;
        
        bool sol=solve(arr, index,k,n, DP);
        return sol;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends