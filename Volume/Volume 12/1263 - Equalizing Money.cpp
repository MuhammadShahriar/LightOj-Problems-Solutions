///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///


/**

Let say Si is the sum of all money of the nodes lie in i-th connected component of graph. And Szi is the size of i-th connected component.
Now for all connected component Si should be divisible by Szi and Si/Szi should be equal for all connected components.

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
int vis[mx], cost[mx];
vi comp[mx];

void dfs ( int u, int typ )
{
    comp[typ].PB ( u );
    vis[u] = 1;

    for ( auto v : adj[u] ) {
        if ( !vis[v] ) dfs ( v, typ );
    }
}

int main()
{

    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {

        for ( int i = 0; i < mx; i++ ) {
            adj[i].clear();
            comp[i].clear();

            cost[i] = 0;
            vis[i] = 0;
        }

        int n, m;
        scanf ( "%d%d", &n, &m );
        for ( int i = 1; i <= n; i++ ) scanf ( "%d", &cost[i] );

        for ( int i = 1; i <= m; i++ ) {
            int u, v;
            scanf ( "%d%d", &u, &v );

            adj[u].PB ( v );
            adj[v].PB ( u );
        }

        int cnt = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( !vis[i] ) {
                dfs ( i, ++cnt );
            }
        }

        set <int > s;
        bool done = 1;

        for ( int i = 1; i <= cnt; i++ ) {
            int sum = 0;
            for ( auto u : comp[i] ) {
                sum += cost[u];
            }

            if ( sum % sz(comp[i]) == 0 ) {
                s.insert ( sum / sz(comp[i]) );
            }

            else done = 0;
        }

        if ( sz ( s ) == 1 && done ) printf ( "Case %d: Yes\n", tc );
        else printf ( "Case %d: No\n", tc );
    }


    return 0;
}















