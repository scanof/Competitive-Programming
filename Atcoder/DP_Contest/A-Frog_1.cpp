#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,r,l) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout<< #x<< " " << x<<el

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll INF = LONG_LONG_MAX;
const double PI = atan(1)*4;
const int MAXN = 1e5+20;
const double EPS= 1e-10;

int h[MAXN];
int dp[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<< setprecision(2)<< fixed;
    int n;
    cin>> n;
    forn(i,n){
        cin>> h[i];
    }
    dp[0]=0;
    dp[1]= abs(h[0]-h[1]);
    fore(i,2,n-1){
        dp[i]= min(dp[i-1]+ abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]) );
    }
    cout<< dp[n-1]<<el;
}
