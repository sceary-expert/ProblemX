//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string ans = "", up = "", low = "";
        for(auto &it : str )
        {
            if(it <= 'Z' && it >= 'A')up += it;
            else low += it;
        }
        sort(up.begin(), up.end());
        sort(low.begin(), low.end());
        int b1 = 0, b2 = 0;
        for(auto &it : str )
        {
            if(it <= 'Z' && it >= 'A')ans += up[b1++];
            else ans += low[b2++];
        }
        return ans;
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends