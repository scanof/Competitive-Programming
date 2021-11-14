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
struct node{
  int sum, mx, mn;
  node(){
  }
  node(int s, int m1, int m2):sum(s),mx(m1),mn(m2){}
};

const node neutro = {0,-inf, inf};

struct stree{
  int n;  vector<node> t;
  stree(int m){
    n = m;   t.resize(n<<2);
  }
  stree(vector<int> &a){
    n = sz(a);
    t.resize(n<<2);
    build(1,0, n-1, a);
  }
  inline node oper(node a, node b){
    return node(a.sum + b.sum, max(a.mx, b.mx), min(a.mn, b.mn));   
  }
  void build(int v, int tl, int tr, vector<int> &a){
    if(tl==tr){
      t[v]= {a[tl], a[tl], a[tl]};  return ;
    }
    int tm = (tr+tl)/ 2;
    build(v*2, tl, tm, a);
    build(v*2+1, tm+1, tr, a);
    t[v] = oper(t[v*2],t[v*2+1]);
  }
  node query(int v, int tl, int tr, int l, int r){
    if(tl>r || tr<l) return neutro;
    if(l<=tl && tr<=r) return t[v];
    int tm = (tl+tr)/2;
    return oper(query(v*2, tl, tm, l, r),
           query(v*2+1, tm+1, tr, l, r));
  }
  void upd(int v, int tl, int tr, int pos, int val){
    if(tl==tr){
      t[v] = {val,val,val};  return ;
    }
    int tm = (tr+tl)/ 2;
    if(pos<= tm)  upd(v*2, tl, tm, pos, val);
    else  upd(v*2+1, tm+1, tr, pos, val);
    t[v] = oper(t[v*2], t[v*2+1]);
  }
  void upd(int pos, int val){ upd(1,0,n-1,pos,val); }
  node query(int l, int r){ return query(1,0,n-1,l,r); }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int n, q;
  cin>> n>> q;
  vi a(n);
  forn(i,n){
    cin>> a[i];
  }
  stree st(a);
  forn(i,q){
    int op;
    cin>> op;
    if(op==1){
      int l, r;
      cin >> l>> r;
      --l, --r;
      node cur = st.query(l, r);
      cout << cur.sum - cur.mx - cur.mn << el;
    }else{
      int pos, val;
      cin>> pos >> val;
      pos--;
      st.upd(pos, val);
    }
  }
}
