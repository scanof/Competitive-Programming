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

typedef __int128_t ll;
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
  vector<ll> a(2);
  a[1] = 1;
  for(int i = 2; i < 100; ++i){
    a.push_back(6*a[i-1] - a[i-2]);
    if(a[i]>=1e16) break;
  }
  long long n;
  while(cin>> n && n){
    int ans = 0;
    for(int i = 2; i < sz(a); ++i){
      ll x = a[i];
      if(x>n) break;
      ll l = 0, r = n + 2;
      while(l + 1 < r){
        ll mid = (l + r)/2;
        if(mid*(mid+1)/2 <= x*x) l = mid;
        else r = mid;
      }
      if(l*(l+1)/2 == x*x && l <= n) ++ans;
    }
    cout << ans << el;
  }

}
