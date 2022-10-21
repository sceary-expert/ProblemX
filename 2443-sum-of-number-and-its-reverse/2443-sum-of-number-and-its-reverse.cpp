class Solution {
public:
    int rev(int i)
    {
        int r = 0;
        while(i)
        {
            int k = i%10;
            i /= 10;
            r *= 10;
            r += k;
        }
        return r;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++)
        {
            // string s = to_string(i);
            // reverse (s.begin(), s.end());
            int t = rev(i);
            if(t + i == num)return true;
        }
        return false;
    }
};