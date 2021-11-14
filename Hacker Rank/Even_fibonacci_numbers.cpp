//https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
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
const int MAXN = 90;
const double EPS= 1e-10;

ll even[MAXN];
int t;
ll n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<< setprecision(2)<< fixed;

    even[0]=0;
    even[1]=1;
    fore(i,2,MAXN-1){
        even[i]=even[i-1]+even[i-2];
    }
    cin>> t;
    while(t--){
        cin>> n;
        int uper1 = lower_bound(even,even+MAXN,n)-even;
        if(even[uper1]>n){
            --uper1;
        }
        while(even[uper1]%2!=0){
            --uper1;
        }
        cout<< (even[uper1+2]-1)/2 <<el;
    }
}
