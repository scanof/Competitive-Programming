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
const int MAXN = 20;
const double PI = acos(-1);
const double EPS= 1e-10;
const ll limite = 1e16;

int dr[] = {1,-1,0, 0,1,-1,-1, 1}; // trick to explore an implicit 2D grid
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int grid[MAXN][MAXN];
int n;
ll dp[20][1<<20];
int allmask = 0;

ll go(int idx, int mask){
    if(idx== n){
        return mask== allmask;
    }
    ll &r = dp[idx][mask];
    if(r!=-1) return r;
    r = 0;
    forn(i,n){
        if(!(mask & (1<<i)) && grid[idx][i]){
            r+= go(idx+1, mask | (1<<i));
        }
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<< setprecision(20)<< fixed;
    int t ;
    cin>> t;
    while(t--){
        cin>> n;
        memset(dp, -1, sizeof dp);
        forn(i,n){
            forn(j,n){
                cin>> grid[i][j];
            }
        }
        allmask = (1<<n)-1;
        cout<< go(0,0)<<el;
    }
}
