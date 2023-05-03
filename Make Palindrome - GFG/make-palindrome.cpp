//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        map<string, int>mp;
        int cnt = 0;
        for(auto &s : arr)
        {
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            if(mp[rev_s] > 0)
            {
                mp[rev_s]--;
                cnt--;
            }
            else{
                mp[s]++;
                cnt++;
            }
        }
        if(cnt > 1)return false;
        string str = "";
        for(auto m : mp)
        {
            if(m.second == 1)
            {
                str = m.first;
            }
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return str == rev_str;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends