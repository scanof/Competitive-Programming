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
  
  ll u, v;
  cin>> u>> v;
  if(u>v || (u&1LL)!=(v&1LL)){
    cout << -1 << el;
    return 0;
  }else if(u == v){
    if(u == 0) cout << 0 << el;
    else cout << 1 << el<< u << el;
    return 0;
  }
  
  ll x = (v - u)/2;
/*
  a+b = a^b + 2(a&b)
  v = u + 2(a&b)
  (v - u)/2 = (a&b)
  x = (a&b)
  a = x
  b = x
  a + b = v - u
  a + b + u = v
  a |= u
*/

  ll a = x | u;
  ll b = x;
  if(a + b == v && (a^b)==u){
    cout << 2 << el;
    cout << a << " "<< b << el;
    return 0;
  }
  cout << 3 << el;
  cout << u << " "<< x << " " << x << el;
}
