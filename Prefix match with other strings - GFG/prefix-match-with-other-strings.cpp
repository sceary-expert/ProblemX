//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++





class Solution{   
public:
    int klengthpref(string a[], int n, int k, string str){    
        vector<string>arr;
        for(int i = 0; i < n; i++)arr.push_back(a[i]);
        sort(arr.begin(), arr.end());
        string s = "";
        for(int i = 0; i < k; i++)
        {
            s += str[i];
        }
        // cout<<s<<endl;
        int lefty = lower_bound(arr.begin(), arr.end(), s) - arr.begin();
        s[k - 1] += 1;//(str[k] + 1) ;
        // cout<<s<<endl;
        int righty = lower_bound(arr.begin(), arr.end(), s) - arr.begin();
        // for(int i = 0; i < n; i++)cout<<arr[i]<<" ";
        // cout<<endl;
        
        // cout<<"left : "<<lefty;
        // cout<" right : "<<righty<<endl;
        
        return righty - lefty;
        
        
        
        // bool f = false;
        // if("ab" > "aba")
        // {
        //     cout<<"left"<<endl;
        // }
        // else if("ab" == "abc")
        // {
        //     cout<<"same";
        // }
        // else cout<<"right";
        // return 0;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends