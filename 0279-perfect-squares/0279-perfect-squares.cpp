class Solution {
public:
    int numSquares(int n) {
        
        static vector<int>minSquareElements({0});
        //minSquareElements[0] = 0;
        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j * j <= i; j++)
        //     {
        //         minSquareElements[i] = min(minSquareElements[i], 1 + minSquareElements[i - j * j]);
        //     }
        // }
        
        while(minSquareElements.size() <= n)
        {
            int sqr = INT_MAX, m = minSquareElements.size();
            for(int i = 1; i * i <= m; i++)
            {
                sqr = min(sqr, 1 + minSquareElements[m - i * i]);
            }
            minSquareElements.push_back(sqr);
        }
        
        return minSquareElements[n];
    }
};