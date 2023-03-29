//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    map<int, int>mp;
    int countSubstring(string S)
    {
        mp[0]++;
        int ans = 0, sum = 0;
        for(auto it : S)
        {
            if(it >= 'a' && it <= 'z')sum++;
            else sum--;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends