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

// Complejidad aprox O(1)
struct dsu{
  vi p, r; int num_sets;
  void init(int n){
    p.assign(n, 0), r.assign(n, 1), num_sets = n;
    iota(all(p), 0);
  }
  int find_set(int i){
    return (p[i] == i ? i : p[i] = find_set(p[i]));
  }
  bool is_same_set(int i, int j){
    return find_set(i) == find_set(j);
  }
  void union_set(int i, int j){
    int x = find_set(i), y = find_set(j);
    if(x == y) return;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
    r[y] += r[x], r[x] = 0;
    --num_sets;
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int n, q;
  cin>> n >> q;
  unordered_map<string,int> mp;
  string s;
  forn(i,n){
    cin>> s;
    mp[s] = i;
  }
  dsu uf;
  uf.init(n);
  forn(i,q){
    int op;
    string s1;
    cin>> op>> s>> s1;
    int u, v;
    u = mp[s], v = mp[s1];
    if(op==1) uf.union_set(u, v);
    else cout << (uf.is_same_set(u,v) ? "yes" : "no") << el; 
  }
}
