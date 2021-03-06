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
const ll MOD = 1e9+7;
int n, k;
ll dp[101][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
//    cout<< setprecision(2)<< fixed;
    cin>> n>> k;
    int arr[n];
    forn(i,n){
        cin>> arr[i];
    }
    sort(arr, arr+n);
    forn(i,arr[0]+1){
        dp[1][i]=1;
    }
    fore(i,2,n){
        forn(j, k+1){
            if(j==0){
                dp[i][j]= 1;
            }else if(j<=arr[i-1] ){
                dp[i][j]= (dp[i-1][j] + dp[i][j-1])%MOD;
            }else{
                dp[i][j]= (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-arr[i-1]-1] +MOD)%MOD;
            }
        }
    }
    cout<< dp[n][k] <<el;
}
