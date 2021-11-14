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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

// Complexity
// Preprocessing O(n)  query O(n/sqrt(n) + sqrt(n))
// Update O(1)
inline int idx(int i, int j){
  return i + 2*j;
}

vector<int> g[2*nax];
struct sqrt_decomp{
  vector<vector<int>> esquinas, esq_adj;
  vector<vector<vector<bool>>> can;
  int n, len;
  sqrt_decomp(int n_){ // preprocessing
    n = n_;
    len = (int) sqrt (n + .0) + 1;
    int S = len;
    if(len*(len-1)>=n) --S;
    esquinas = vector<vector<int>>(S, vector<int>(4));
    esq_adj = vector<vector<int>>(S, vector<int>(4, -1));
    can = vector<vector<vector<bool>>>(S, vector<vector<bool>>(4, vector<bool>(2*len + 1)));
    
    forn(i,S){
      esquinas[i][0] = idx(0, i*len);
      esquinas[i][1] = idx(1, i*len);
      esquinas[i][2] = idx(0, min(n,(i+1)*len)-1);
      esquinas[i][3] = idx(1, min(n,(i+1)*len)-1);
    }
  }

  inline void bfs(int u, int dt, int src, int bloque){
    queue<int> q;
    q.push(u);
    can[bloque][src][u - dt] = 1;
    int v;
    while(sz(q)){
      u = q.front();
      q.pop();
      forn(i,sz(g[u])){
        v = u + i - 2;
        if(v < 0 || g[u][i] <= 0 || v >= 2*n) continue;
        if(v/(2*len) != bloque){
          can[bloque][src][2*len] = 1;
          esq_adj[bloque][src] = v;
          continue;
        }
        if(!can[bloque][src][v - dt]){
          can[bloque][src][v - dt] = 1;
          q.push(v);
        }
      }
    }
  }

  inline void update(int pos){
    int bpos = pos/(2*len);
    forn(i,4){
      can[bpos][i].assign(2*len+1, false);
      bfs(esquinas[bpos][i], esquinas[bpos][0], i, bpos);
    }
  }

  inline bool bfs_bloque(int u, int t, int bloque){
    if(u == t) return 1;
    int &sq = esquinas[bloque][0];
    vector<bool> seen(2*len);
    queue<int> q;
    q.push(u);
    seen[u - sq] = 1;
    int v;
    while(sz(q)){
      u = q.front();
      q.pop();
      forn(i,sz(g[u])){
        v = u + i - 2;
        if(v < 0 || g[u][i] <= 0 || v >= 2*n) continue;
        if(v/(2*len) != bloque){
          continue;
        }
        if(seen[v-sq]) continue;
        q.push(v);
        seen[v-sq] = 1;
        if(v == t) return 1;
      }
    }
    return 0;
  }

  inline bool query(int l, int r){
    int bl = l/(2*len);
    int br = r/(2*len);
    if(bl == br && bfs_bloque(l, r, bl)) return 1;
    set<int> seen, seen2;
    forn(i,4){
      if(can[bl][i][l-esquinas[bl][0]]){
        seen.insert(esquinas[bl][i]);
      }
    }
    forn(i,4){
      if(can[br][i][r-esquinas[br][0]]){
        seen2.insert(esquinas[br][i]);
      }
    }
    for(int x : seen2){
      if(seen.count(x)) return 1;
    }
    queue<int> q;
    for(int x : seen){
      q.push(x);
    }
    while(sz(q)){
      int u = q.front();
      q.pop();
      if(u < 0) exit(0);
      int bu = u/(2*len);
      int sq = 0;
      forn(i,4){
        if(esquinas[bu][i]==u) sq = i;
      }
      forn(i,4){
        if(can[bu][sq][esquinas[bu][i]-esquinas[bu][0]]){
          if(seen2.count(esquinas[bu][i])) return 1;
          if(seen.count(esquinas[bu][i])) continue;
          seen.insert(esquinas[bu][i]);
          q.push(esquinas[bu][i]);
        }
      }
      if(can[bu][sq][2*len]){
        if(seen2.count(esq_adj[bu][sq])) return 1;
        if(seen.count(esq_adj[bu][sq])) continue;
        seen.insert(esq_adj[bu][sq]);
        q.push(esq_adj[bu][sq]);
      }
    }
    return 0;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t;
  cin>> t;
  while(t--){
    int n;
    cin>> n;
    forn(i,2*n){
      g[i] = {0,0,0,0,0};
    }
    string s;
    sqrt_decomp sq(n);
    while(cin>> s && s != "Exit"){
      int x0, y0, x1, y1;
      cin>> x0>> y0>> x1>> y1;
      x0--; y0--; x1--; y1--;
      int u = idx(x0,y0);
      int v = idx(x1,y1);
      if(u > v) swap(u, v);
      if(s =="Open"){
        g[u][v-u+2]++;
        g[v][u-v+2]++;
        sq.update(u);
        sq.update(v);
      }else if(s == "Close"){
        // assert(g[u][v-u+2]>=1);
        
        g[u][v-u+2] = g[u][v-u+2]-1;
        g[v][u-v+2] = g[v][u-v+2]-1;
        
        sq.update(u);
        sq.update(v);
      }else{
        cout << (sq.query(u, v) ? "Y" : "N") << el;
      }
    }
    forn(i,2*n){
      g[i].clear();
    }
  }
}