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

const int mx = 5e2+12;
vii adj[mx];
int dp[mx];

void dfs ( int u, int cost )
{
    if ( dp[u] <= cost ) return;
    dp[u] = cost;

    for ( auto v : adj[u] ) {
        dfs ( v.F, max ( cost, v.S ) );
    }
}


int main()
{
    optimize();

    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < mx; i++ ) {
            adj[i].clear();
            dp[i] = inf;
        }

        int n, m;
        scanf ( "%d%d", &n, &m );
        for ( int i = 1; i <= m; i++ ) {
            int u, v, w;
            scanf ( "%d%d%d", &u, &v, &w );
            u++, v++;

            adj[u].PB ( { v, w } );
            adj[v].PB ( { u, w } );
        }

        int t;
        scanf ( "%d", &t );
        t++;
        dfs ( t, 0 );


        printf ( "Case %d:\n", tc );
        for ( int i = 1; i <= n; i++ ) {
            if ( dp[i] != inf ) printf ( "%d\n", dp[i] );
            else printf ( "Impossible\n" );
        }
    }


    return 0;
}

















