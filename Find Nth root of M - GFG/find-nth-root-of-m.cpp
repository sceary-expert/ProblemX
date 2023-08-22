//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int mn = 1, mx = m;
	    int ans = -1;
	    while(mn <= mx)
	    {
	        int mid = (mn + mx) / 2;
	        long long int num = pow(mid, n);
	       // cout<<"mid "<<mid<<endl;
	       // cout<<"num "<<num<<endl;
	        if(num > m || num < 0)
	        {
	            mx = mid - 1;
	        }
	        else if(num < m)
	        {
	            mn = mid + 1;
	            
	        }else{
	            return mid;
	        }
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends