//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
int mod_exp(int base, int exp, int mod)
{
    int res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
        int modulo(string s,int m)
        {
            //code here
            int res = 0;
            int p = 0, n = s.size();
            for(int i = n - 1; i >= 0; i--, p++)
            {
                if(s[i] == '0')continue;
                int num = mod_exp(2, p, m);
                res = (res + num) % m;
                
            }
            return res;
        }
};

// 50
// 110010

// 4
// 100

// 7
// 111

// 3
// 11

// 1101



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends