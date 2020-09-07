///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


const int mx = 1e3+123;
ll fact[mx], nCr[mx][mx];

int main()
{
    fact[0] = 1;
    for ( int i = 1; i <= 1000; i++ ) fact[i] = modMul( i, fact[i-1] );

    for ( int i = 0; i <= 1000; i++ ){
        for ( int j = 0; j <= i; j++ ){
            if ( j == 0 || j == i ) nCr[i][j] = 1;
            else nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] ) % MOD;
        }
    }

    int t;
    scanf ( "%d", &t );

    for ( int tc = 1; tc <= t; tc++ ) {
        int n, m, k;
        scanf ( "%d%d%d", &n, &m, &k );

        int d = n - k, l = m - k;
        ll ans = fact[d];

        for ( int i = 1; i <= l; i++ ) {
            if ( i % 2 ) ans = modSub( ans, modMul( nCr[l][i], fact[d-i] ) );
            else ans = modAdd( ans, modMul( nCr[l][i], fact[d-i] ) );
        }

        ans = modMul( ans, nCr[m][k] );

        printf ( "Case %d: %lld\n", tc, ans );
    }



    return 0;
}
















