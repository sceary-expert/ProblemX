class Solution {
public:
    int numSquares(int n) {
        
        vector<int>minSquareElements(n + 1, INT_MAX);
        minSquareElements[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                minSquareElements[i] = min(minSquareElements[i], 1 + minSquareElements[i - j * j]);
            }
        }
        return minSquareElements[n];
    }
};