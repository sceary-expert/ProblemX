class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x = 0, T = minutesToTest / minutesToDie;
        while(pow((T + 1), x) < buckets)
        {
            x++;
        }
        return x;
    }
};