//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isValid(int x, int y, int m, int n)
    {
        if(x < 0 || y < 0 || x >= m || y >= n)return false;
        return true;
    }
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] != 1)continue;
                int count_of_zeros = 0;
                for(auto &d : dir)
                {
                    int x = i + d[0], y = j + d[1];
                    if(isValid(x, y, m, n) && matrix[x][y] == 0)count_of_zeros++;
                }
                if(count_of_zeros > 0 && count_of_zeros % 2 == 0)
                {
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends