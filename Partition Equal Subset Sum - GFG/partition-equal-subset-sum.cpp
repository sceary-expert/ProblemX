//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool IsFormationOfTargetPossible(int ind, int arr[], int N, int tar, vector<vector<int>>&DP)
    {
        // cout<<"tar "<<tar<<endl;
        if(ind >= N)
        {
            // cout<<"tar "<<tar<<endl;
            return tar == 0;
        }
        
        if(tar < 0)return false;
        // cout<<"line 22"<<endl;
        // cout<<"ind "<<ind<<" tar "<<tar<<endl;
        // cout<<"DP "<<DP[ind][tar]<<endl;
        if(DP[ind][tar] != -1)
        {
            return DP[ind][tar] == 1;
        }
        // cout<<"line 25"<<endl;
        bool f1 =  IsFormationOfTargetPossible(ind + 1, arr, N, tar, DP);
        bool f2 =  IsFormationOfTargetPossible(ind + 1, arr, N, tar - arr[ind], DP);
        
        if(f1 == true || f2 == true)
        {
            DP[ind][tar] = 1;
        }
        else DP[ind][tar] = 0;
        return DP[ind][tar] == 1;
        
    }
    int equalPartition(int N, int arr[])
    {
        int tot = 0;
        for(int i = 0; i < N; i++)
        {
            tot += arr[i];
        }
        if(tot % 2)return false;
        int tar = tot / 2;
        // cout<<"tar "<<tar<<endl;
        vector<vector<int>>DP(N + 1, vector<int>(tar + 1, -1));
        // for(auto &it : DP)
        // {
        //     for(auto &i : it)cout<<i<<" "; cout<<endl;
        // }
        return IsFormationOfTargetPossible(0, arr, N, tar, DP);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends