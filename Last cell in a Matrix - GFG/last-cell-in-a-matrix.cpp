//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // 0 = up
    // 1 = right
    // 2 = down
    // 3 = left
    int start;
    int x, y;
    void DFS(vector<vector<int>>&matrix, int p, int q, int r, int c)
    {
        if(x != -1 && y != -1)return;
        if(matrix[p][q] != 0)
        {
            //same direction
            start = (start + 1) % 4;
            matrix[p][q] = 0;
        }
        int prev_p = p, prev_q = q;
        if(start == 0)
        {
            p--;
        }
        else if(start == 1)
        {
            q++;
        }
        else if(start == 2)
        {
            p++;
        }
        else if(start == 3)
        {
            q--;
        }
        if(p >= r || q >= c || p < 0 || q < 0)
        {
            x = prev_p;
            y = prev_q;
            return;
        }
        DFS(matrix, p, q, r, c);
    }
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        start = 1;
        x = -1, y = -1;
        DFS(matrix, 0, 0, R, C);
        return {x, y};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends