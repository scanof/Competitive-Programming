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
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

const int mod = 1000000007;
const int N = 11;
inline int add(int a, int b){
  if(a+b>=mod) return a + b - mod;
  return a + b;
}

struct matrix{ // define N
  int r, c, m[N][N];
  matrix(int r, int c):r(r),c(c){
    memset(m, 0, sizeof m);
  }
  matrix operator *(const matrix &b){
    matrix c = matrix(this->r, b.c);
    forn(i,this->r){
      forn(k,b.r){
        if(!m[i][k]) continue;
        forn(j,b.c){
          c.m[i][j] = add(c.m[i][j], 1ll*m[i][k]*b.m[k][j]%mod);
        }
      }
    }
    return c;
  }
};
matrix pow(matrix b, ll e){
  matrix c = matrix(b.r, b.c);
  forn(i,b.r) c.m[i][i] = 1;
  while(e){
    if(e&1LL) c = c*b;
    b = b*b , e/=2;
  }
  return c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int t;
  cin>> t;
  for1(tt,t){
    int n, m;
    cin>> n>> m;
    matrix A(n,n);
    forn(i,m){
      int u, v;
      cin>> u>> v;
      --u, --v;
      A.m[u][v] = 1;
    }
    cout << "Case "<< tt << ":" <<el;
    int q;
    cin>> q;
    while(q--){
      int u, v;
      cin>> u>> v;
      ll k;
      cin>> k;
      --u, --v;
      cout<< (pow(A,k)).m[u][v] << el;
    }
  }
}
