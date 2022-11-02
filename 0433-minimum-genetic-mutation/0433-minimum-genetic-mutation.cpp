class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>b;
        for(auto s : bank)b.insert(s);
        if(b.find(end) == b.end())return -1;
        //cout<<"hgf"<<endl;
        queue<string>q;
        q.push(start);
        int step = 0;
        while(q.size())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto s = q.front();
               // cout<<s<<endl;
                q.pop();
                if(s == end)return step;
                
                for(int j = 0; j < s.size();j++)
                {
                    string temp = s;
                    for(char c = 'A'; c <= 'Z'; c++)
                    {
                        temp[j] = c;
                        //if(j == 7)cout<<temp<<endl;
                        if(b.find(temp) != b.end())
                        {
                            q.push(temp);
                            b.erase(temp);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};