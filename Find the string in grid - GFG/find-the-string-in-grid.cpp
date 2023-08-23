//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool is_val(int x, int y, int m, int n){
        if(x >= m || y >= n || x < 0 || y < 0)return false;
        return true;
    }
    vector<vector<int>>dir = {{0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
    bool start_dfs(int i, int j, int k, int m, int n,
    string &word, int ind, vector<vector<char>>&grid)
    {
        if(ind >= word.size())return true;
        char t = grid[i][j];
        grid[i][j] = '$';
    
        int x = i + dir[k][0], y = j + dir[k][1];
        if(is_val(x, y, m, n) && grid[x][y] == word[ind])
        {
            if(start_dfs(x, y, k, m, n, word, ind + 1, grid))
            {
                grid[i][j] = t;    
                return true;
            }
        }
    
        grid[i][j] = t;
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int m = grid.size(), n = grid[0].size();
	    vector<vector<int>>ans;
	    for(int i = 0; i < m; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            if(grid[i][j] != word[0])continue;
	            if(word.size() == 1)
	            {
	                ans.push_back({i, j});
	                continue;
	            }
	            for(int k = 0; k < 8; k++)
	            {
	                bool f = start_dfs(i, j, k, m, n, word, 1, grid);
	                if(f)
	                {
	                    ans.push_back({i, j});
	                    break;
	                }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends