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
const int nax = 19;

int n, m;
vi g[nax];
ll dp[nax][1<<nax];
int mn;

ll go(int u, int mask){
  ll &r = dp[u][mask];
  if(r!=-1) return r;
  r = 0;
  for(int v : g[u]){
    if(v < mn) continue;
    if((1<<v)&mask){
      if(v == mn){
        ++r;
      }
      continue;
    }
    if(v == mn) continue;
    r += go(v, mask | (1<<u) | (1<<mn) | (1<<v));
  }
  return r;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  cin>> n>> m;
  forn(i,m){
    int u, v;
    cin>> u >> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  ll ans = 0;
  forn(i, n){
    mn = i;
    memset(dp, -1, sizeof dp);
    for(int v : g[i]){
      if(v < i) continue;
      ans += go(v, 0);
    }
  }
  assert(ans%2==0);
  cout << ans/2 << el;
}
