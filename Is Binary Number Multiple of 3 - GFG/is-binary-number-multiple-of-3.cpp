//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int mod_exp(int base, int exp, int mod)
{
    int res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)//if exp is odd
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}	
	int isDivisible(string s){
	    int rem = 0;
	    int n = s.size();
	    int p = 0;
	    for(int i = n - 1; i >= 0; i--, p++)
	    {
	        if(s[i] == '0')continue;
	        int curr = mod_exp(2, p, 3);
	       // cout<<curr<<" ";
	        curr += rem;
	        rem = curr % 3;
	       // cout<<rem<<endl;
	    }
	    return rem == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends