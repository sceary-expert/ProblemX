//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int>v;
        for(int i = 0; i < n; i++)
        {
            int curr_sum = 0;
            for(int j = 0; j < n; j++)
            {
                curr_sum += matrix[i][j];
            }
            v.push_back(curr_sum);
        }
        
        for(int i = 0; i < n; i++)
        {
            int curr_sum = 0;
            for(int j = 0; j < n; j++)
            {
                curr_sum += matrix[j][i];
            }
            v.push_back(curr_sum);
        }
        
        int mx = *max_element(v.begin(), v.end());
        int ans = 0;
        for(auto &it : v)
        {
            ans += abs(mx - it);
        }
        return ans / 2;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends