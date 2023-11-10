//https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
class Solution{   
public:
    string printMinNumberForPattern(string S){
        //calculate how many D are after i;
        int n = S.size();
        vector<int>suff(n, 0);
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(S[i] == 'D')cnt++;
            else{
                suff[i] = cnt;
                cnt = 0;
            }
        }
        string s = "";
        s += ((cnt + 1) + '0');
        int prev = cnt + 1;
        for(int i = 0; i < n; i++)
        {
            if(S[i] == 'I')
            {
                prev += suff[i] + 1;
                s += (prev + '0');
            }
            else{
                s += s[s.size() - 1] - 1;
            }
        }
        return s;
        
    }
};
