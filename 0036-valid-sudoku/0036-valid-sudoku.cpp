class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>>row(10, vector<int>(10, 0));
        vector<vector<int>>col(10, vector<int>(10, 0));
        vector<vector<int>>box(10, vector<int>(10, 0));
        
        //check for row and col
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')continue;
                int curr = board[i][j] - '0';
                row[i][curr]++;
                col[j][curr]++;
                
                if(row[i][curr] > 1 || col[j][curr] > 1)return false;
            }
        }
        
        //check for each boxes
        
        //map the boxes
        //map<pair<int, int>, int>mp;
        //pos, corresponding box
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')continue;
                int curr = board[i][j] - '0';
                if(i < 3)
                {
                    if(j < 3)
                    {
                        box[1][curr]++;
                        if(box[1][curr] > 1)return false;
                    }
                    else if(j < 6)
                    {
                        box[2][curr]++;
                        if(box[2][curr] > 1)return false;
                    }
                    else{
                        box[3][curr]++;
                        if(box[3][curr] > 1)return false;
                    }
                }
                else if(i < 6)
                {
                    if(j < 3)
                    {
                        box[4][curr]++;
                        if(box[4][curr] > 1)return false;
                        
                    }
                    else if(j < 6)
                    {
                        box[5][curr]++;
                        if(box[5][curr] > 1)return false;
                    }
                    else{
                        box[6][curr]++;
                        if(box[6][curr] > 1)return false;
                    }
                }
                else{
                    if(j < 3)
                    {
                        box[7][curr]++;
                        if(box[7][curr] > 1)return false;
                    }
                    else if(j < 6)
                    {
                        box[8][curr]++;
                        if(box[8][curr] > 1)return false;
                    }
                    else{
                        box[9][curr]++;
                        if(box[9][curr] > 1)return false;
                    }
                }
            }
        }
        return true;
    }
};