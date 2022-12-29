class Solution {
public:
    // Template for Leetcode
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define _mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
        #define _d(x) cout << #x <<" "; _p(x); cout << endl;
void _p(ll t)     {cout << t;}
void _p(int t)    {cout << t;}
void _p(string t) {cout << t;}
void _p(char t)   {cout << t;}
void _p(lld t)    {cout << t;}
void _p(double t) {cout << t;}
void _p(ull t)    {cout << t;}
//template <class T, class V> void _p(pair <T, V> p);
//template <class T> void _p(vector <T> v);
//template <class T> void _p(set <T> v);
//template <class T, class V> void _p(map <T, V> v);
//template <class T> void _p(multiset <T> v);
template <class T, class V> void _p(pair <T, V> p) {cout << "{"; _p(p.first); cout << ","; _p(p.second); cout << "}";}
template <class T> void _p(vector <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(set <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T> void _p(multiset <T> v) {cout << "[ "; for (T i : v) {_p(i); cout << " ";} cout << "]";}
template <class T, class V> void _p(map <T, V> v) {cout << "[ "; for (auto i : v) {_p(i); cout << " ";} cout << "]";}
#define _a(x) (x).begin(), (x).end()
#define _f first
#define _s second
#define _pb push_back
#define _pob pop_back
#define _i int
#define _sz(x) ((_i)(x).size())
#define _vvi vector<vector<_i>>
#define _vi vector<_i>
#define _vvb vector<vector<bool>>
#define _mnh priority_queue<_i, vector<_i>, greater<_i>>
#define _mxh priority_queue<_i>
#define _m map<_i, _i>
#define _um unordered_map<_i, _i>
#define _vs vector<string>
#define _vvs vector<vector<string>>
#define _vc vector<char>
#define _vvc vector<vector<char>>
#define _vpi vector<pair<_i, _i>
#define _pi pair<_i, _i>

    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long int>f(n);
        vector<long long int>l(n);
        long long int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            f[i] = sum;
        }
        sum = 0;
        for(int i = n - 1; i  >= 0; i--)
        {
            sum += nums[i];
            l[i] = sum;            
        }
        // _d(l);
        // _d(f);
        long long int ans = 1e5 + 5, ind = 0;
        for(int i = 0; i < n; i++)
        {
            long long int d1 = i + 1, d2 = n - i - 1;
            //cout<<d1<<" "<<d2<<endl;
            int j = 0, k = 0;
            if(d1)j = (int)(0.5 + (f[i] / d1));
            if(d2)k = (int)(0.5 + (l[i + 1] / d2));
            long long int d = abs(j - k);
            if(i == 2)
            {
                // d(f[i]);
                // d(l[i]);
                // cout<<j<<" --------- "<<k<<endl;
            }
            // d(i);
            // d(d);
            if(d < ans)
            {
                ans = d;
                ind = i * 1L;
            }
        }
        return (int)ind;
    }
};