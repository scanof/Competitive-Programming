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
const int mod = 998244353;
 
const double inf = 1e9;
const ld pi = acos(-1);
const ld eps= 1e-8;
 
int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};
const int nax = 1e7+10;
int lp[nax+1];
vector<int> pr; // It can be sped up if change for an array
void sieve(){
  fore(i,2,nax-1){
    if (lp[i] == 0) {
      lp[i] = i; pr.pb(i);
    }
    for (ll j=0, mult= i*pr[j]; j<sz(pr) && pr[j]<=lp[i] && mult<nax; ++j, mult= i*pr[j])
      lp[mult] = pr[j];
  }
}
ll fact [nax+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(2)<< fixed;
  sieve();
  vector<pair<ll,ll>> res;
  int t,num,pr;
  ll prod,sum;
  cin >> t;
  for1(w,t){
    sum=0;
    prod=1;
    forn(i,nax){
      fact[i]=1;
    }
    int can;
    cin >> can;
    forn(i,can){
      cin >> num;
      if(num>0){
        while(num !=1){
          pr=lp[num];
          prod/=fact[pr];
          fact[pr]+=1;
          prod*=fact[pr];
          num/=pr;
        }
      }else{
        num=(-num);
        while(num !=1){
          pr=lp[num];
          prod/=fact[pr];
          fact[pr]-=1;
          prod*=fact[pr];
          num/=pr;
        }
      }
      sum+=prod;
      if(sum>=mod){
        sum-=mod;
      }
    }
    cout << "Case " << w << ": "<< sum << el;
  }
}