//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    #define d(x) cout<<#x<<" " <<x<<endl;
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        vector<int>differences;
        vector<int>ranges = range[0];
        vector<int>prefix_distance;
        vector<vector<int>>newRanges;
        for(auto &r : range)
        {
            int start = r[0], end = r[1];
            if(start <= ranges.back() + 1)
            {
                ranges[1] = max(ranges[1], end);
            }
            else{
                int diff = ranges[1] - ranges[0];
                diff++;
                // d(diff);
                differences.push_back(diff);
                newRanges.push_back(ranges);
                ranges = r;
            }
        }
        int diff = ranges[1] - ranges[0];
        diff++;
        // d(diff);
        differences.push_back(diff);
        newRanges.push_back(ranges);
        int sum = 0;
        for(auto &difference : differences)
        {
            sum += difference;
            prefix_distance.push_back(sum);
        }
        // cout<<sum<<endl;
        
        vector<int>answer;
        for(auto &query : queries)
        {
            if(query > sum)
            {
                answer.push_back(-1);
                continue;
            }
            auto itr = lower_bound(prefix_distance.begin(), prefix_distance.end(), query);
            int ind = itr - prefix_distance.begin();
            int diff = *itr - query;
            // cout<<diff<<endl;
            answer.push_back(newRanges[ind][1] - diff);
        }
        return answer;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends