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

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

const int mx = 1e5+123;
int t[mx*3], a[mx], prop[3*mx], dp[mx*3], id[mx];
bool vis[3*mx];

void shift ( int id, int b, int e )
{
    int mid = ( b + e ) >> 1;
    t[id*2] = modAdd( t[id*2], modMul ( mid - b + 1,  prop[id] ) );
    t[id*2+1] = modAdd( t[id*2+1], modMul( e - mid,  prop[id] ) );

    prop[id*2] =  modAdd( prop[id*2], prop[id] );
    prop[id*2+1] = modAdd( prop[id*2+1], prop[id] );

    vis[id*2] = vis[id*2+1] = 1;
    prop[id] = vis[id] = 0;
}


void upd ( int id, int b, int e, int i, int j, int val )
{
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ) {
        t[id] = modAdd( t[id], modMul( e - b + 1, val ) );
        prop[id] = modAdd( prop[id], val );
        vis[id] = 1;
        return;
    }

    if ( vis[id] ) shift ( id, b, e );
    int mid = ( b + e ) >> 1;

    upd ( id*2, b, mid, i, j, val );
    upd ( id*2+1, mid+1, e, i, j, val );

    t[id] = modAdd( t[id*2], t[id*2+1] );
}

int ask ( int id, int b, int e, int i, int j )
{
    if ( b > j || e < i ) return 0;
    if ( b >= i && e <= j ) return t[id];

    if ( vis[id] ) shift ( id, b, e );
    int mid = ( b + e ) >> 1;

    int ret1 = ask ( id*2, b, mid, i, j );
    int ret2 = ask ( id*2+1, mid+1, e, i, j );

    return modAdd( ret1, ret2 );
}

int main()
{
    optimize();

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i <= 3e5; i++ ) {
            dp[i] = vis[i] = prop[i] = t[i] = 0;
        }

        vi v;
        int n;
        scanf ( "%d", &n );

        for ( int i = 1; i <= n; i++ ) {
            scanf ( "%d", &a[i] );
            v.PB ( a[i] );
        }

        sort ( all ( v ) );

        for ( int i = 1; i <= n; i++ ) {
            id[i] = upper_bound( all ( v ), a[i] ) - v.begin();
            id[i]++;
        }

        for ( int i = 1; i <= n; i++ ) {
            dp[i] = modAdd( 1, ask ( 1, 1, n, id[i]-1, id[i]-1 ) );
            upd ( 1, 1, n, id[i], n, dp[i] );
        }

        int ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            ans = modAdd( ans, dp[i] );
        }

        printf ( "Case %d: %d\n", tc, ans );

    }


    return 0;
}

















