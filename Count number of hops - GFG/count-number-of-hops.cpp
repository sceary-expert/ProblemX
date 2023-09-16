//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long m = (long long)(1e9 + 7);
    vector<int>DP;
    long long HowManyWaysToReach(int n)
    {
        if(n < 0)return 0;
        if(n == 0)return 1;
        if(DP[n] == -1)
        {
            long long ans = 0;
            long long a1 = HowManyWaysToReach(n - 1);
            long long a2 = HowManyWaysToReach(n - 2);
            long long a3 = HowManyWaysToReach(n - 3);
            ans = (a1 + a2 + a3) % m;
            DP[n] = ans;
        }
        return DP[n];
        
    }
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        DP.resize(n + 1, -1);
        
        long long ans = HowManyWaysToReach(n);
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends