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
typedef ll ld;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 0;


struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=eps&&abs(y-p.y)<=eps;}
	bool operator!=(pt p){ return !operator==(p);}
	bool operator<(pt p)const{ // for convex hull/set/map
		return x<p.x-eps||(abs(x-p.x)<=eps&&y<p.y-eps);}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	///DOT
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator%(pt p){ // 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	/// 2D from now on
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>=eps;
  }
};
ld orient(pt a, pt b, pt c){  ///C: >0 left, ==0 on AB, <0 right
  return (b-a)%(c-a);
}
bool proper_inter(pt a, pt b, pt c, pt d){
  ld oa = orient(c,d,a),
     ob = orient(c,d,b),
     oc = orient(a,b,c),
     od = orient(a,b,d);
  if(oa*ob<0 && oc*od<0){
    return true;
  }
  return false;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  while(cin>> n && n){
    vector<ii> a(n);
    forn(i,n){
      cin >> a[i].fi >> a[i].se;
    } 
    sort(all(a));
    vector<pt> p(n);

    forn(i,n) p[i] = {a[i].first, a[i].second};
    
    vector<int> ord, ord2;
    forn(i,n){
      if(p[i].left(p[0], p[n-1])){
        ord.pb(i);
      }else{
        ord2.pb(i);
      }
    }
    vector<int> orden;  
    cout << n << el;
    reverse(all(ord));
    for(int x : ord){
      cout << p[x].x << " " << p[x].y << el;
      orden.pb(x);
    }
    for(int x : ord2){
      cout << p[x].x << " " << p[x].y << el;
      orden.pb(x);
    }
    vector<pt> pp = p;
    forn(i,n) p[i] = pp[orden[i]];
    forn(i,n){
      forn(j,n){
        if(i==j) continue;
        assert(!proper_inter(p[i],p[(i+1)%n],p[j],p[(j+1)%n]));
      }
    }
  }
}
