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
const int nax = 1000020;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
int dp[nax];

inline int add(int a, int b){
  if(a+b>=mod) return a+b-mod;
  return a+b;
}

bool check(int i, int mask){
  return !(mask&(1<<i));
}

int go(int j){
  if(j == nax) return 1;
  if(j > nax) return 0;
  int &r = dp[j];
  if(r!=-1) return r;
  r = 0;
   
  // L
  // L
  r = add(r, go(j + 1)); // ponerla vertical
  
  /// LLLX
  /// LXXX

  /// LXXX
  /// LLLX
  r = add(r, 2ll*go(j + 4)%mod);

  
  // LL
  // LL
  r = add(r, go(j + 2)); // ponerla horizontal
  
  // LLX  XLL
  // XXX  XXX
  r = add(r, 4ll*go(j+3)%mod);
  return r;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int t;
  cin>> t;
  memset(dp, -1, sizeof dp);
  while(t--){
    cin>> n;
    cout << go(nax-n) << el;
  }
}
