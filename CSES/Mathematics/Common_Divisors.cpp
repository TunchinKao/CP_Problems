#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REP1(i, n) for(int i = 1; i <= (int)n; i++)
#define debug(x) cout << #x << ": " << x << endl;
#define depii(x) cout << "(" << x.first << ", " << x.second << ")";
#define devec(x) for(auto v: x) cout << v << endl;
#define eb emplace_back
#define F first
#define S second
#define al(x) x.begin(), x.end()
#define mp make_pair
#define yccc cin.tie(0), ios_base::sync_with_stdio(false)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T>
using p = pair<T, T>;

template<typename T>
using vec = vector<T>;
int cnt[1000001];
int main(){
	yccc;		
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll val;
		cin >> val;
		cnt[val]++;
	}
	for(int gcd = 1000000; gcd > 0; gcd--){
		int x = 0;
		for(int j = gcd; j <= 1000000; j+=gcd){
			x += cnt[j];
		}
		if(x >= 2){
			cout << gcd << endl;
			break;
		}
	}
	return 0;
}

