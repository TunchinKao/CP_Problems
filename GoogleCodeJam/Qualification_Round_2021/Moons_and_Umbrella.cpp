// AC
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using vec = vector<T>;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
 
#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define eb emplace_back
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define debug(x) cout << " > " << #x << ": " << x << endl;
#define devec(v) cout << " > " << #v << ": "; for (auto i : v) cout << i << ' '; cout << endl;
#define devec2(v) cout << " > " << #v << ":\n"; for (auto i : v) { for (auto k : i) cout << ' ' << k; cout << endl; }
 
const int INF = 1e9;
const int nINF = -1e9;
const ll llINF = 4*1e18;
const int MOD = 1e9+7;
 
ll& pmod(ll& a, ll b) { a = (a+b) % MOD; return a; }
ll& pmod(ll& a, ll b, ll c) { a = (a+b) % c; return a; }
ll& mmod(ll& a, ll b) { a = (a-b+MOD) % MOD; return a; }
ll& mmod(ll& a, ll b, ll c) { a = (a-b+c) % c; return a; }
ll& tmod(ll& a, ll b) { a = (a*b) % MOD; return a; }
ll mul(ll a, ll b) { return (a*b) % MOD; }
ll mul(ll a, ll b, ll c) { return (a*b) % c; }
ll POW(ll a, ll b) { ll res=1; do { if(b%2) tmod(res,a); tmod(a,a); } while (b>>=1); return res; }
ll FAC(ll a) { ll res = 1; REP1(i, a) tmod(res, i); return res; }
 
template<typename T1, typename T2>
ofstream operator<<(ofstream& out, pair<T1, T2> a) { cout << a.F << ' ' << a.S; return out; }
int T, N;
int dp[10005][2];
int main(){
    cin >> T;
    REP1(C, T){
        int x, y;
        cin >> x >> y;
        memset(dp, 0, sizeof(dp));
        string str;
        cin >> str;
        int Ans = 0;
        // dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i < str.length(); i++)
        {
            if(str[i] == 'J'){
                dp[i][0] = INF;
                if(str[i-1] == 'C'){
                    dp[i][1] = dp[i-1][0] + x;
                }else if(str[i-1] == 'J'){
                    dp[i][1] = dp[i-1][1];
                }else{
                    dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
                }
            }else if (str[i] == 'C' ){
                dp[i][1] = INF;
                if(str[i-1] == 'J'){
                    dp[i][0] = dp[i - 1][1] + y;
                }else if(str[i-1] == 'C'){
                    dp[i][0] = dp[i - 1][0];
                }else{
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                }
                
            }else{
                if(str[i-1] == 'C'){

                    dp[i][0] = dp[i - 1][0];
                    dp[i][1] = dp[i - 1][0] + x;
                }else if(str[i-1] == 'J'){

                    dp[i][0] = dp[i - 1][1] + y;
                    dp[i][1] = dp[i - 1][1];
                }else {

                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
                    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
                }
            
            }
            // REP(r, str.length()){
            //     cout << dp[r][0] << ' ';
            // }
            // cout << endl;
            // REP(r, str.length()){
            //     cout << dp[r][1] << ' ';
            // }
            // cout << endl;
        }
        Ans = min(dp[str.length() - 1][0], dp[str.length() - 1][1]);
        cout << "Case #" << C << ": " << Ans << endl;
    }
    return 0;
}