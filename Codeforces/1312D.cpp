#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 2e5+200, mod = 998244353;

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b * b % mod, e /= 2)
		if (e&1) ans = 1LL*ans * b % mod;
	return ans;
}

int fact[nax];

int C(int n, int k){
  if(k < 0 || n < 0 || k > n) return 0;
  return 1ll*fact[n]*(1ll*binpow(fact[k], mod - 2)*binpow(fact[n-k], mod-2)%mod)%mod;
}

inline int add(int a, int b){
  if(a+b>=mod) return a+b-mod;
  return a+b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin>> n>> m;
  if(n == 2){
    cout << 0 << el;
    return 0;
  }
  fact[0] = 1;
  forn(i,nax-1) fact[i+1] = 1ll*(i+1)*fact[i]%mod;

  int ans = 1ll*C(m, n-1)*(n-2)%mod;
  ans = 1ll*ans*binpow(2, n-3)%mod;
  cout << ans << el;
}
