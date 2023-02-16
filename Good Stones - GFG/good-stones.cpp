//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<int>v;
    vector<bool>vis;
    int DFS(int n, vector<int>&arr, int ind)
    {
        if(ind < 0 || ind >= n || v[ind] > 0)return 1;
        if(vis[ind])
        {
            v[ind] = -1;
            return -1;
        }
        if(v[ind] < 0)
        {
            return -1;
        }
        // if()return 1;
        
            
        vis[ind] = true;
        
        int res = DFS(n, arr, ind + arr[ind]);
        if( res < 0)
        {
            v[ind] = -1;
            return -1;
        }
        else{
            v[ind] = 1;
            return 1;
        }
        
        
    }
    int goodStones(int n,vector<int> &arr){
        v.resize(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(v[i] != 0)continue;
            vis.resize(n, false);
            v[i] = DFS(n, arr, i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(v[i] > 0)ans++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends