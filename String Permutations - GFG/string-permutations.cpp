//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> find_permutataion(string &s, int n, vector<bool>&vis)
    {
        vector<string>v;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == false)
            {
                vis[i] = true;
                auto p = find_permutataion(s, n, vis);
                for(auto &it : p)
                {
                    v.push_back(s[i] + it);
                }
                vis[i] = false;
            }
        }
        if(v.size() == 0)v.push_back("");
        sort(v.begin(), v.end());
        return v;
    }
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.size();
        vector<bool>vis(n, false);
        return find_permutataion(S, n, vis);
        
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends