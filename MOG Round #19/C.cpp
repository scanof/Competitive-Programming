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
  cout << setprecision(20)<< fixed;
  int t;
  cin>> t;
  for1(tt,t){
    int n;
    cin>> n;
    vi a(n);
    forn(i,n){
      cin>> a[i];
    }
    ll sum = 0;
    // forn(l,n){
    //   ll cur = 0;
    //   int mn = a[l];
    //   fore(r,l,n-1){
    //     cur += a[r];
    //     mn = min(mn, a[r]);
    //     ll cur2 = cur - 1ll*mn*(r-l+1);
    //     // d(cur2);
    //     sum += cur2;
    //   }
    // }
    // d(sum);
    ll ans2 = sum;
    vector<ll> sums(n);
    sum = 0;
    ll ans = 0;
    forn(i,n){
      sums[i] = sum + (i ? sums[i-1] : 0);
      sum += a[i];
      ll cur = sum*(i+1) - sums[i];
      ans += cur;
    }
    // d(ans);
    vector<int> le(n);
    stack<int> pl;
    forn(i,n){
      while(sz(pl) && a[pl.top()]>=a[i]) pl.pop();
      if(sz(pl)) le[i] = pl.top() + 1;
      pl.push(i);
    }
    vi ri(n, n-1);
    while(sz(pl)) pl.pop();
    for(int i = n-1; i>=0; --i){
      while(sz(pl) && a[pl.top()]>a[i]) pl.pop();
      if(sz(pl)) ri[i] = pl.top() - 1;
      pl.push(i);
    }
    forn(i,n){
      ll lefts = (i - le[i]);
      ll rights = (ri[i] - i);
      ll cant = 0;
      cant = 0;
      cant += (rights + 1)*(lefts+1);
      cant += rights*(rights+1)/2*(lefts+1);
      cant += (lefts)*(lefts+1)/2 * (rights+1);
      ans -= 1ll*a[i]*cant;
    }
    cout << "Case "<< tt <<": " << ans << el;
  }
}
