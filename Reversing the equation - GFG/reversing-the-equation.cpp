//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            string curr = "";
            stack<string>st;
            for(auto &it : s)
            {
                if(it >= '0' && it <= '9')
                {
                    curr += it;
                }
                else{
                    st.push(curr);
                    curr = "";
                    curr += it;
                    st.push(curr);
                    curr = "";
                }
            }
            st.push(curr);
            string ans = "";
            while(st.size())
            {
                ans += st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends