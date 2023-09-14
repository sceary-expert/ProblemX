//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = (int)(1e9 + 7);
	int InHowManyWaysSumCanBeMade(int arr[], int n, int sum, int ind, vector<vector<int>>&DP)
	{
	    if(sum < 0)return 0;
	    if(ind >= n)
	    {
	        if(sum == 0)return 1;
	        return 0;
	    }
	    if(DP[ind][sum] != -1)return DP[ind][sum];
	    
	    int take = InHowManyWaysSumCanBeMade(arr, n, sum - arr[ind], ind + 1, DP);
	    int not_take = InHowManyWaysSumCanBeMade(arr, n, sum, ind + 1, DP);
	   
	   
	    return DP[ind][sum] = (take + not_take) % mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        //DP[i] = from ith position in how many ways I can make sum
        vector<vector<int>>DP(n + 1, vector<int>(sum + 1, -1));
        
        int ans = InHowManyWaysSumCanBeMade(arr, n, sum, 0, DP);
        // for(auto &it : DP)
        // {
        //     for(auto &i : it)cout<<i<<"     ";
        //     cout<<endl;
        // }
        return ans;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends