//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        stack<char>st;
        for(auto it : s)
        {
            if(st.size() == 0)
            {
                st.push(it);
                continue;
            }
            if(it == st.top())st.pop();
            else st.push(it);
            
        }
        string ans = "";
        while(st.size())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == ""? "-1" : ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends