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
const int nax = 4e3 + 20;

int mat[nax][nax];

int query(int x0, int y0, int x1, int y1){
  return mat[x1][y1] - mat[x1][y0-1] - mat[x0-1][y1] + mat[x0-1][y0-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n, m, k;
  cin>> n>> m>> k;
  for1(i,n){
    for1(j,m){
      char c;
      cin>> c;
      if(c=='.') mat[i][j] = 1;
    }
  }
  for1(i,n){
    for1(j,m){
      mat[i][j] += mat[i][j-1];
    }
  }
  for1(j,m){
    for1(i,n){
      mat[i][j] += mat[i-1][j];
    }
  }
  int ans = 0;
  for1(i,n){
    for1(j,m){
      if(query(i,j,i+k-1,j)==k) ++ans;
      if(k==1) continue;
      if(query(i,j,i,j+k-1)==k) ++ans;
    }
  }
  cout << ans << el; 
}

// precomputamos en O(N*M)
// query es O(1)