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
int dp[2][nax][4][4][4];

inline int add(int a, int b){
  if(a+b>=mod) return a+b-mod;
  return a+b;
}

bool check(int i, int mask){
  return !(mask&(1<<i));
}

int go(int i, int j, int mask, int mask2, int mask3){
  if(j == nax) return 1;
  if(i == 2) return go(0, j + 1, mask2, mask3, 0);
  int &r = dp[i][j][mask][mask2][mask3];
  if(r!=-1) return r;
  if(!check(i, mask)){ //if(arr[i][j]){
    return r = go(i + 1, j, mask, mask2, mask3);
  }
  r = 0;
  if(i + 1 < 2 && check(i+1,mask)){
    // L
    // L
    r = add(r, go(i + 1, j, mask | (1<<i) | (1<<(i+1)), mask2, mask3)); // ponerla vertical
  }
  
  if(j + 1 < nax && check(i, mask2)){
    // LL
    r = add(r, go(i + 1, j, mask | (1<<i), mask2 | (1<<i), mask3)); // ponerla horizontal
  }

  if(j + 2 < nax && i + 1 < 2 && check(i,mask2) && check(i,mask3) && check(i+1,mask)){
    ///  XLL
    ///  L
    r = add(r, go(i + 1, j, mask | (1<<i) | (1<<(i+1)) , mask2 | (1<<i), mask3 | (1<<i)));
  }

  if(j + 2 < nax && i + 1 < 2 && check(i,mask2) && check(i,mask3) && check(i+1,mask3)){
    ///  XLL
    ///    L
    r = add(r, go(i + 1, j, mask | (1<<i), mask2 | (1<<i), mask3 | (1<<i) | (1<<(i+1)) ));
  }

  if(j + 2 < nax && i + 1 < 2 && check(i+1,mask2) && check(i+1,mask3) && check(i+1,mask)){
    ///  X
    ///  LLL
    r = add(r, go(i + 1, j, mask | (1<<i) | (1<<(i+1)) , mask2 | (1<<(i+1)), mask3 | (1<<(i+1))));
  }

  if(j + 2 < nax && i - 1 >= 0 && check(i,mask2) && check(i,mask3) && check(i-1,mask3)){
    ///    L
    ///  XLL
    r = add(r, go(i + 1, j, mask | (1<<i), mask2 | (1<<i), mask3 | (1<<i) | (1<<(i-1))));
  }

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
    cout << go(0, nax-n, 0, 0, 0) << el;
  }
}
