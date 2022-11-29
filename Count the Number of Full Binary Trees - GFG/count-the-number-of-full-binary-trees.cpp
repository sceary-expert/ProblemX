//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int mod = 1e9 + 7;
    int N = 1e5 + 1;
    long long int numoffbt(long long int arr[], int n){
        vector<int>DP(N, 0);
        int mx = INT_MIN, mn = INT_MAX;
        long long int ans = 0;
        for(int i = 0; i < n; i++)
        {
            DP[arr[i]] = 1;
            int t = arr[i];
            mx = max(mx, t);
            mn = min(mn, t);
        }
        
        for(int i = mn; i <= mx; i++)
        {
            if(DP[i] != 1 || DP[i] == 0)continue;
            for(int j = mn; j * j <= i; j++)
            {
                if(i % j == 0 && DP[i / j] != 0 && DP[j] != 0)
                {
                    if(i / j != j)
                    {
                        DP[i] += 2 * (DP[i / j] * DP[j]);
                    }
                    else{
                        DP[i] += DP[j] * DP[j];
                    }
                  DP[i] %= mod;
                }
                
            }
            ans += DP[i];
            ans %= mod;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends