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
const int nax = 2e3 + 20;

vi g[nax];
int n;

int bfs(int u){
  vi dist(n,-1);
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  while(sz(q)){
    u = q.front();
    q.pop();
    for(int v : g[u]){
      if(dist[v]==-1){
        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
  int mn = *min_element(all(dist));
  if(mn == -1) return 1e9;
  return *max_element(all(dist));
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int m;
  cin>> n>> m;
  forn(i,m){
    int u, v;
    cin>> u>> v;
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  int mx = 0;
  forn(i,n){
    mx = max(mx, bfs(i));
  }
  if(mx == 1e9){
    cout << "=[" << el;
  }else{
    cout << "=] "<< mx << el;
  }
}
