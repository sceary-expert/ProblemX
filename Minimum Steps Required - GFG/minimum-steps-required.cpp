//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    string s = "" ;
    s += str[0];
    for(auto it : str)
    {
        if(it != s[s.size() - 1])
        {
            s += it;
        }
    }
    // cout<<"--"<<s<<"--"<<endl;
    // cout<<s.size()<<" "<<s.size() / 2<<endl;
    return 1 + (s.size() / 2);
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends