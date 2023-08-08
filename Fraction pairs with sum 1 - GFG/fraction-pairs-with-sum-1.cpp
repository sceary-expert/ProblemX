//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<pair<int, int>, int>mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a = numerator[i], b = denominator[i];
            int gcd = __gcd(a, b);
            a /= gcd; b /= gcd;
            int x = b - a;
            ans += mp[{x, b}];
            mp[{a, b}]++;
            // double d = (numerator[i] * 1.0) / (denominator[i] * 1.0);
            // double target = 1.0 - d;
            // cout<<"d "<<d<<" target "<<target<<" freq "<<mp[target]<<endl;
            // ans += mp[target];
            // mp[d]++;
            // cout<<" d "<<d<< " mp[d] "<<mp[d]<<endl;
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
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends