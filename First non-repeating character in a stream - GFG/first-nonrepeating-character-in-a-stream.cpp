//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    map<char, int>mp;
		    char fnr = A[0];
		    int p = 0;
		    string ans = "";
		    for(int i = 0; i < A.size(); i++)
		    {
		        char c = A[i];
		        mp[c]++;

		        if(mp[fnr] != 1 )
		        {
		            for(; p <= i; p++)
		            {
		                if(mp[A[p]] == 1)
		                {
		                    fnr = A[p];
		                    break;
		                }
		            }
		            
		        }
		        if(mp[fnr] != 1)
		        {
		            ans += "#";
		        }
		        else ans += fnr;
		    }
		    return ans;
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends