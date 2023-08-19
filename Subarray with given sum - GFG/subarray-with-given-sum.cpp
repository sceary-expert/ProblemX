//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        queue<pair<int, int>>q;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            // index_of_sum[sum] = i + 1;
            q.push({arr[i], i + 1});
            sum += arr[i];
            while(sum > s)
            {
                sum -= q.front().first;
                q.pop();
            }
            if(sum == s && q.size())
            {
                return {q.front().second, i + 1};
            }
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends