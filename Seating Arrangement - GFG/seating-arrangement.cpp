//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        int answer = 0;
        if(m == 1)
        {
            int ans = 0;
            if(seats[0] == 0)ans++;
            return n <= ans;
        }
        if(seats[0] == 0 && seats[1] == 0)
        {
            answer++;
            seats[0] = 1;
        }
        if(seats[m - 1] == 0 && seats[m - 2] == 0)
        {
            answer++;
            seats[m - 1] = 1;
        }
        for(int i = 1; i < m - 1; i++)
        {
            if(seats[i] == 0 && seats[i - 1] == 0 && seats[i + 1] == 0)
            {
                // cout<<i<<endl;
                seats[i] = 1;
                answer++;
            }
            
        }
        // cout<<answer<<endl;
        return n <= answer;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends