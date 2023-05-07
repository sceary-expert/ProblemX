//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        int n = str.size();
        string left = "", right = "";
        left += str[0];
        right += str[0];
        string ans(n, 'z');
        for(int i = 1; i < n; i++)
        {
            // cout<<str[i]<<" "<<str[i - 1]<<endl;
            if(str[i] > str[i - 1])
            {
                break;
            }
            string temp = left + right;
            if(temp < ans)ans = temp;
            left += str[i];
            right = str[i] + right;
            
            
        }
        string temp = left + right;
        if(temp < ans)ans = temp;
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends