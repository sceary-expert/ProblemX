//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<int>sortedStart, sortedEnd;
  int maxTime;
  
    int isMidLaptopSufficient(int mid, int n)
    {
        int ans = 0;
        int runningTime = 0, p = 0, q = 0;
        for(; runningTime <= maxTime; runningTime++)
        {
            while(p < n && sortedStart[p] == runningTime)
            {
                p++;
                mid++;
            }
            while(q < n && sortedEnd[q] == runningTime)
            {
                q++;
                mid--;
            }
            ans = max(ans, mid);
            int avg = runningTime + 1;
            
            if(p < n && q < n)
            {
                avg = min(sortedStart[p], sortedEnd[q]);
            }
            else if(p < n)
            {
                avg = sortedStart[p];
            }
            else if(q < n)
            {
                avg = sortedEnd[q];
            }
            runningTime = avg - 1;
        }
        return ans;
        
    }
    int minLaptops(int N, int start[], int end[]) {
        maxTime = 0;
        for(int i = 0; i < N; i++)
        {
            maxTime = max(maxTime, start[i]);
            maxTime = max(maxTime, end[i]);
            sortedStart.push_back(start[i]);
            sortedEnd.push_back(end[i]);
        }
        
        sort(sortedStart.begin(), sortedStart.end());
        sort(sortedEnd.begin(), sortedEnd.end());
        int ans = isMidLaptopSufficient(0,N);
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends