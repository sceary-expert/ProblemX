//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        if(S.size() != T.size())return 0;
        string s = "", t = "";
        vector<int>v1, v2;
        for(int i = 0; i < S.size(); i++)
        {
            char c = S[i];
            
            if(c != '#')
            {
                v1.push_back(i);
                s += c;
            }
                
        }
        for(int i = 0; i < T.size(); i++)
        {
            char c = T[i];
            if(c != '#')
            {
                v2.push_back(i);
                t += c;
            }
        }
        if(s != t)return 0;
        for(int i = 0; i < v1.size(); i++)
        {
            int a = v1[i], b  = v2[i];
            if(s[i] == 'A')
            {
                if(b > a)return 0;
            }
            else {
                if(b < a)return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends