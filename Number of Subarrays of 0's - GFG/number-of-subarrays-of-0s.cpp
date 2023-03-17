//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long int
long long int no_of_subarrays(int n, vector<int> &arr) {
    map<ll, ll>mp;
    mp[0]++;
    ll ans = 0, sum = 0;
    for(auto it : arr)
    {
        if(it == 0)sum++;
        else{
        // cout<<sum<<endl;
        if(sum > 0)
        {
            ans +=((sum * (sum + 1)) / 2);
        }
        sum = 0;
        }
    }
    if(sum > 0)
        {
            ans +=((sum * (sum + 1)) / 2);
        }
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends