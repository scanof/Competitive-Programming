#include <bits/stdc++.h>
#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el
#define sz(v) ((int)v.size())
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector<int> vi;
typedef vector<ll> vll;
const ld pi = acos(-1), eps = 1e-8;
const int inf = 1e9, mod = 998244353;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n, mx_sz = 0; cin >> n;
  vector<string> s(n);
  cin.ignore();
  forn(i, n) {
    getline(cin, s[i]);
    forn(j,sz(s[i])){
      if(s[i][j]!=' '){
        s[i] = s[i].substr(j);
        break;
      }
    }
    while(sz(s[i])>1 && s[i].back()==' ') s[i].pop_back(); 
    mx_sz = max(mx_sz, sz(s[i]));
  }
  vector<string> ans(n+2);
  ans[0] = string(mx_sz+2, '*');
  ans[n+1] = ans[0];
  for1(i, n){
    ans[i] = string(mx_sz+2, ' ');
    ans[i][0] = ans[i][mx_sz+1] = '*';
    int sz = sz(s[i-1]);
    int rest, idx = 0;
    if((sz) % 2 == 0){
      rest = (mx_sz - sz)/2;
    } else{
      rest = (mx_sz - sz)/2;
      if(rest&1) ++rest;
    }
     
    fore(j, rest+1, rest+sz){
      ans[i][j] = s[i-1][idx++];
    }
  }
 
  forn(i, n+2) cout << ans[i] << el;
}