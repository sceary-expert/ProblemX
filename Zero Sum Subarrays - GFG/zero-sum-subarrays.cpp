//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    #define ll long long int
    ll fact(int n)
    {
        if(n <= 1)return 1;
        return n * fact(n - 1);
    }
    ll NcR(ll n, ll r)
    {
        return (fact(n)/(fact(r) * fact(n - r)));
    }
    long long int findSubarray(vector<long long int> &arr, int n ) {
        ll ans = 0;
        vector<ll>pref(n, 0);
        ll sum = 0;
        map<ll, ll>mp;
        mp[0]++;
        for(int i = 0; i < n; i++)
        {
            sum += (1L * arr[i]);
            pref[i] = sum;
            mp[sum]++;
        }
        for(auto &it : mp)
        {
            ll num = it.first, freq = it.second;
            
            if(freq < 2)continue;
            
            ans += NcR(freq, 2);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends