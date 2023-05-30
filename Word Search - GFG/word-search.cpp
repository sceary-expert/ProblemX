//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>>directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool is_valid(int x, int y, int m, int n)
    {
        if(x < 0 || x >= m || y < 0 || y >= n)return false;
        return true;
    }
    bool DFS(vector<vector<char>>&board, string word, 
    int m, int n, int i, int j, int ind)
    {
        
        if(ind == word.size())return true;
        char b = board[i][j];
        board[i][j] = '#';
        for(auto &direction : directions)
        {
            int x = i + direction[0], y = j + direction[1];
            if(is_valid(x, y, m, n) && board[x][y] == word[ind])
            {
                if(DFS(board, word, m, n, x, y, ind + 1))return true;
            }
        }
        board[i][j] = b;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                if(DFS(board, word, m, n, i, j, 1))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends