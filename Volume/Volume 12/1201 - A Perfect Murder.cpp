///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///


/**

Just think about making minimum number of mosquito's alive. It is minimum vertex cover problem.
So ans is n - minimum vertex cover in graph, where n is number of mosquito's.

**/


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

const int mx = 1e3+123;

vi adj[mx];
int dp[mx][3], par[mx];

int dfs ( int u, int f1 )
{
    if ( dp[u][f1] != -1 ) return dp[u][f1];
    int ret = 0;

    for ( int v : adj[u] ) {
        if ( par[u] == v ) continue;
        par[v] = u;
        if ( !f1 ) ret += dfs ( v, 1 );
        else ret += min ( dfs ( v, 0 ), dfs ( v, 1 ) );
    }

    return dp[u][f1] = ret + f1;
}



int main()
{
    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        mem ( dp, -1 );
        mem ( par, -1 );

        for ( int i = 0; i < mx; i++ ) adj[i].clear();
        int n, m;
        scanf ( "%d%d", &n, &m );

        for ( int i = 1; i <= m; i++ ) {
            int u, v;
            scanf ( "%d%d", &u, &v );
            adj[u].PB ( v );
            adj[v].PB ( u );
        }

        int ans = 0;
        for ( int i = 1; i <= n; i++ ) if ( dp[i][0] == -1 ) ans += min ( dfs ( i,  1 ), dfs ( i, 0 ) );

        printf ( "Case %d: %d\n", tc, n - ans );
    }

    return 0;
}

















