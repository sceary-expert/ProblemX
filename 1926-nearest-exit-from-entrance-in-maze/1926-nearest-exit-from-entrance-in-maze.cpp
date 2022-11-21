class Solution {
public:
    bool outOfBorder(int x, int y, int m, int n)
    {
        if(x < 0 | y < 0 || x >= m || y >= n)return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>>q;
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        vector<vector<int>>dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int level = 0;
        while(q.size())
        {
            int sz = q.size();
            for(int o = 0; o < sz; o++)
            {
                auto frontElement = q.front();
                q.pop();
                int x = frontElement[0], y = frontElement[1];
                
                for(auto &d : dir)
                {
                    int new_x = x + d[0], new_y = y + d[1];
                    bool isoutOfBorder = outOfBorder(new_x, new_y, m, n);
                    
                    if(isoutOfBorder && level != 0)return level;
                    if(isoutOfBorder == false && maze[new_x][new_y] == '.')
                    {
                        maze[new_x][new_y] = '+';
                        q.push({new_x, new_y});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};