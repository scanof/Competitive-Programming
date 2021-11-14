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
const int nax = 2003;

int n, h, l, r;
int dp[nax][nax];
int a[nax];

int go(int i, int time){
  if(i == n) return 0;
  int &v = dp[i][time];
  if(v!=-1) return v;
  int nxt = (time + a[i])%h;
  v = go(i + 1, nxt) + (l <= nxt && nxt <= r);
  nxt = (time + a[i] - 1)%h;
  v = max(v, go(i + 1, nxt) + (l <= nxt && nxt <= r));
  return v;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin>> n >> h>> l>> r;
  forn(i,n){
    cin>> a[i];
  }
  memset(dp, -1, sizeof dp);
  cout << go(0, 0) << el;
}
