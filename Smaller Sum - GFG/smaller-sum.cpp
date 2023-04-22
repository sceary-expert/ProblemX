//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
#define ll long long
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<ll>prefix_sum;
        ll sum = 0;
        vector<int>sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        for(auto &it : sorted_arr)
        {
            sum += it;
            prefix_sum.push_back(sum);
        }
        vector<ll>answer;
        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            auto itr = lower_bound(sorted_arr.begin(), sorted_arr.end(), a);
            int ind = itr - sorted_arr.begin();
            if(ind - 1 >= 0)
            {
                answer.push_back(prefix_sum[ind - 1]);
            }
            else answer.push_back(0);
        }
        return answer;
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends