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

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin>> t;
  while(t--){
    int n, k, l;
    cin>> n >> k>> l;
    vi a(n+1), b;
    a[0] = -1000;
    forn(i,n){
      cin>> a[i+1];
    }
    forn(i,k) b.pb(i);
    for(int i = k; i>= 1; --i) b.pb(i);
    assert(sz(b) == 2*k);
    int cur = 0;
    bool death = false;
    forn(i,n+1){
      bool pos = 0;
      if(a[i]+b[cur]>l){
        if(cur>=k && a[i-1]+b[cur]<=l){
          i--;
          pos = 1;
        }else death = 1;
      }
      if(a[i]+k>l && !pos){
        cur = (cur + 1)%(2*k);
        continue;
      }
      if(i+1==n+1) continue;
      cur = k-1;
      for(int j = cur + 1; j < 2*k; ++j){
        if(a[i+1]+ b[j]<=l){
          cur = j - 1;
          break;
        }
        cur = j;
      }
      cur = (cur + 1)%(2*k);
    } 
    cout << (death ? "No" : "Yes") << el;
  }
}
