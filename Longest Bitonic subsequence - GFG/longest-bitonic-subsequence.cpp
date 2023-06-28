//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int ans = 0;
	    int n = nums.size();
	    vector<int>LISL(n, 1), LISR(n, 1);
	    for(int i = 0; i < n; i++)
	    {
	        int num = nums[i];
	        int mxL = 1;
	        for(int j = 0; j < i; j++)
	        {
	            if(nums[j] < num)
	            {
	                mxL = max(mxL, 1 + LISL[j]);
	            }
	        }
	        LISL[i] = mxL;
	    }
	    for(int i = n - 1; i >= 0; i--)
	    {
	        int num = nums[i];
	        int mxR = 1;
	        for(int j = i + 1; j < n; j++)
	        {
	            if(nums[j] < num)
	            {
	                mxR = max(mxR, 1 + LISR[j]);
	            }
	        }
	        LISR[i] = mxR;
	    }
	    for(int i = 0; i < n; i++)
	    {
	        int num = nums[i];
	        int curr = LISL[i] + LISR[i] - 1;
	        if(curr > ans)ans = curr;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends