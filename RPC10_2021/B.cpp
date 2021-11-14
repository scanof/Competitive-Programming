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
const int nax = 1e5+20;

string multi(int k, int d){
  string ans = "";
  int carry = 0;
  for(int i = k-1; i>=0; --i){
    int cur = d*d + carry;  
    ans.pb('0'+(cur%10));
    carry = cur/10;
  }
  if(carry) ans.pb('0'+carry);
  reverse(all(ans));
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(20)<< fixed;
  int d, k;
  while(cin>> d>> k && d && k){
    string tmp(nax,'0');
    string s = tmp + multi(k,d) + tmp;
    ll ans = 0;
    ll sum = 0;
    ll carry = 0;
    int len = 0;
    for(int i = sz(s) - 1; i>=0; --i){
      sum += (s[i]-'0');
      if(len>=k) sum -= (s[i+k]-'0');
      ll cur = (carry + sum);
      ans += cur % 10;
      carry = cur / 10;
      ++len;
    }
    cout << ans << el;
  }
}
