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

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<char,int> pci;
typedef tuple<int, int, int> tiii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const ll INF = LONG_LONG_MAX;
const int MAXN = 1e3+2;

ll dp[MAXN][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>> n;
    int a[n][2];
    forn(i,n) cin>> a[i][0] >> a[i][1];
    dp[0][0]= a[0][0];
    dp[0][1]= a[0][1];

    for1(i,n-1){
        forn(j,2){
            dp[i][0] = max(dp[i][0], a[i][0] + dp[i-1][j] + abs(a[i-1][(j+1)%2] - a[i][1]));
            dp[i][1] = max(dp[i][1], a[i][1] + dp[i-1][j] + abs(a[i-1][(j+1)%2] - a[i][0]));
        }
    }
    cout<< max(dp[n-1][0],dp[n-1][1])<<el;
}
