//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        queue<int>q;
        int prev = -1;
        int ans = 0;
        for(int i= 0; i < n; i++)
        {
            if(arr[i] == 'A')
            {
                int temp = i - prev;
                if(temp > ans)ans = temp;
            }
            else{
                if(m > 0)
                {
                    m--;
                    q.push(i);
                    int temp = i - prev;
                    if(temp > ans)ans = temp;
                }
                else{
                    prev = q.front();
                    q.pop();
                    int temp = i - prev;
                    if(temp > ans)ans = temp;
                    q.push(i);
                }
            }
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends