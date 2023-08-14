//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int bit = 0;
        for(auto &it : nums)
        bit ^= it;
        int j = -1;
        for(int i = 0; i < 32; i++)
        {
            if((bit&(1<<i)) != 0)
            {
                j = i;
                break;
            }
        }
        int a = 0, b = 0;
        for(auto &it : nums)
        {
            if((it&(1<<j)) != 0)
            {
                a ^= it;
            }else{
                b ^= it;
            }
        }
        if(a > b)swap(a, b);
        return {a, b};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends