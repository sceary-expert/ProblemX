//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void Rec(vector<int>&nums, int n, int start, int end, vector<int>&ans)
    {
        
        
        // vector<int>ans;
        // cout<<"root : "<<root<<endl;
        if(start > end)return ;
        // ans.push_back(nums[root]);
        if(start == end)
        {
            ans.push_back(nums[start]);
            return ;
        }
        int mid = (start + end) / 2;
        ans.push_back(nums[mid]);
        Rec(nums, n, start, mid - 1, ans);
        Rec(nums, n,mid + 1, end, ans);
        // if(left.size())for(auto &it : left)ans.push_back(it);
        // if(right.size())for(auto &it : right)ans.push_back(it);
        return;
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        int n = nums.size();
        // int root = ((n - 1)/ 2);
        int start = 0, end = n - 1;
        Rec(nums, n, start, end, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends