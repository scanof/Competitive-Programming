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
const int nax = 14;

int n;
string s[nax];

int dp[1<<nax][nax+1][nax+1][3][nax];

int go(int mask, int l, int r, int side, int len){
  int &v = dp[mask][l][r][side][len];
  if(v!=-1) return v;
  if(mask == 0 && l == 14 && r == 14){
    return v = 1;
  }
  if(mask == 0 && (l==14 || r==14)){
    l = min(l, r);
    int i = (side == 1 ? len : 0);
    int j = (side == 2 ? len : sz(s[l])-1);
    while(i < j){
      if(s[l][i]!=s[l][j]) return v = 0;
      ++i, --j;
    }
    return v = 1;
  }
  v = 0;
  if(l == 14){
    forn(i,n){
      if(mask&(1<<i)) v += go(mask^(1<<i), i, r, side, len); 
    }
    return v;
  }
  if(r == 14){
    forn(i,n){
      if(mask&(1<<i)) v += go(mask^(1<<i), l, i, side, len); 
    }
    return v;
  }
  int i = (side == 1 ? len : 0);
  int j = (side == 2 ? len : sz(s[r]) - 1);

  while(i < sz(s[l]) && j >= 0){
    if(s[l][i]!=s[r][j]) return v = 0;
    ++i, --j;
  }
  if(i==sz(s[l]) && j<0) return v = go(mask, 14, 14, 0, 0);
  else if(j<0) return v = go(mask, l, 14, 1, i);
  else return v = go(mask, 14, r, 2, j);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin>> n;
  forn(i,n) cin>> s[i];
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  forn(mask,1<<n){
    if(mask == 0) continue;
    int cur = go(mask, 14, 14, 0, 0);
    ans += cur;
  }
  cout << ans << el;
}
