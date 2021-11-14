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
  cout << setprecision(20)<< fixed;
  int n;
  while(cin>> n && n){
    vi a(n);
    int mx = 0;
    forn(i,n){
      cin>> a[i];
      mx = max(a[i], mx);
    }
    ++mx;
    vi dp(mx), dp2(mx);
    forn(i,n){
      dp[a[i]] = max(dp[a[i]], 1);
      dp2[a[i]] = max(dp2[a[i]], 1);
      forn(j,a[i]){
        dp[a[i]] = max(dp[a[i]], dp[j]+1);
      }
      for(int j = mx-1; j>a[i]; --j){
        dp2[a[i]] = max(dp2[a[i]], dp2[j]+1);
      }
    }
    if(*max_element(all(dp)) == *max_element(all(dp2))) cout << "Caution. I will not intervene." << el;
    else cout << "Don't worry. I must intervene."<<el;
  }
}
