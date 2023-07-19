//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int dp[1005][1005];
	int f(int i, int j, string &str)
	{
	  if(i < 0 || j < 0)return 0;
	  if(dp[i][j] != -1)return dp[i][j];
	  if(str[i] == str[j] && i != j)
	  {
	      return dp[i][j] =  1 + f(i - 1, j - 1, str);
	      
	  }
	  return dp[i][j] = max(f(i - 1, j, str), f(i, j - 1, str));
	}
	int LongestRepeatingSubsequence(string str){
	    // Code here
	    memset(dp, -1, sizeof dp);
	    int n = str.size();
	    return f(n - 1, n - 1, str);
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends