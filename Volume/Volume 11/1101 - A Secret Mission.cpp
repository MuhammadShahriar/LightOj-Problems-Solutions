///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**

First of all create minimum spanning tree of the graph.
And Now use heavy light decomposition on this tree to find maximum edge cost in the path s to t.

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

const int mx = 5e4+123;
int par[mx], size[mx];

ll t[mx*3], a[mx], prop[3*mx];
bool vis[3*mx];

int baseArry[mx], basePos[mx], chainNO, chainHead[mx], parent[mx], level[mx], chainInd[mx], ptr, p[mx][40], sz[mx];
vii adj[mx];


void init ( int id, int b, int e )
{
    if ( b == e ) {
        t[id] = baseArry[b];
        return;
    }

    int mid = ( b + e ) >> 1;

    init ( id*2, b, mid );
    init ( id*2+1, mid+1, e );

    t[id] = max ( t[id*2], t[id*2+1] );
}

ll ask ( int id, int b, int e, int i, int j )
{
    if ( b > j || e < i ) return 0;
    if ( b >= i && e <= j ) return t[id];

    int mid = ( b + e ) >> 1;

    ll ret1 = ask ( id*2, b, mid, i, j );
    ll ret2 = ask ( id*2+1, mid+1, e, i, j );

    return max ( ret1, ret2 );
}

int dfs ( int u, int lev )
{
    int ret = 1;
    level[u] = lev;
    for ( auto v : adj[u] ) {
        if ( parent[u] != v.F ) {
            parent[v.F] = u;
            ret += dfs ( v.F, lev+1 );
        }
    }

    sz[u] = ret;
    return ret;
}


void HLD ( int u, int cost, int pU )
{
    if ( chainHead[chainNO] == -1 ) {
        chainHead[chainNO] = u;
    }

    chainInd[u] = chainNO;
    basePos[u] = ++ptr;
    baseArry[ptr] = cost;

    int m = -1, id = -1, c = -1;

    for ( auto v : adj[u] ) {
        if ( v.F != pU ) {
            if ( sz[v.F] > m ) {
                m = sz[v.F];
                id = v.F;
                c = v.S;
            }
        }
    }


    if ( id != -1 ) HLD ( id, c, u );

    for ( auto v : adj[u] ) {
        if ( v.F != pU && v.F != id ) {
            chainNO++;
            HLD ( v.F, v.S, u );
        }
    }
}

void preprocess ( int n )
{
    for ( int i = 1; i <= n; i++ ) p[i][0] = parent[i];

    for ( int j = 1; (1 << j) <= n; j++ ) {
        for ( int i = 1; i <= n; i++ ) {
            if ( p[i][j-1] != -1 ) p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}

int LCA ( int u, int v )
{
    if ( level[u] < level[v] ) swap ( u, v );

    int dist = level[u] - level[v];

    int rise;
    while ( dist > 0 ) {
        rise = log2( dist );
        u = p[u][rise];
        dist -= ( 1 << rise );
    }

    if ( u == v ) return u;

    for ( int i = 20; i >= 0; i-- ) {
        if ( p[u][i] != p[v][i] && p[u][i] != -1 ) {
            u = p[u][i];
            v = p[v][i];
        }
    }

    return parent[u];
}


ll query_ask ( int u, int v )
{
    if ( u == v ) return 0;
    int chainU, chainV = chainInd[v];
    ll ans = 0;

    while ( 1 ) {
        chainU = chainInd[u];
        if ( chainU == chainV ) {
            ans = max (ans, ask ( 1, 1, ptr, basePos[v]+1, basePos[u] ) );
            break;
        }

        ans = max ( ans, ask ( 1, 1, ptr, basePos[chainHead[chainU]], basePos[u] ) );
        u = chainHead[chainU];
        u = parent[u];
    }

    return ans;
}

ll queryAsk ( int u, int v )
{
    int lca = LCA ( u, v );
    return max ( query_ask ( u, lca ), query_ask ( v, lca ) );
}



struct info{
    int u, v, w;
    info ( int u, int v,  int w ) : u(u), v(v), w(w) {}
};

bool cmp ( const info &a, const info &b )
{
    return a.w < b.w;
}

vector < info > edge;


int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

void make_set(int v) {
    par[v] = v;
    size[v] = 1;
}

int cnt;
void union_sets(int a, int b, int w ) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        par[b] = a;
        adj[a].PB ( { b, w } );
        adj[b].PB ( { a, w } );
        cnt++;
        size[a] += size[b];
    }
}

int main()
{
    int T;

    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < mx; i++ ) adj[i].clear();
        edge.clear();

        int n, m;
        scanf ( "%d%d", &n, &m );

        for ( int i = 1; i <= m; i++ ) {
            int u, v, w;
            scanf ( "%d%d%d", &u, &v, &w );
            edge.PB ( info ( u, v, w ) );
        }

        for ( int i = 1; i <= n; i++ ) make_set( i );

        sort ( all ( edge ), cmp );

        cnt = 0;

        for ( auto u : edge ) {
            union_sets( u.u, u.v, u.w );
            if ( cnt == n-1 ) break;
        }

        int root;
        for ( int i = 1; i <= n; i++ ) {
            if ( par[i] == i ) root = i;
        }

        mem ( t, 0 );
        mem ( vis, 0 );
        mem ( prop, 0 );

        ptr = 0, chainNO = 1;
        mem ( p, -1 );
        mem ( chainHead, -1 );


        dfs ( root, 0 );
        HLD ( root, 0, -1 );
        preprocess( n );
        init ( 1, 1, ptr );


        printf ( "Case %d:\n", tc );
        int q;
        scanf ( "%d", &q );
        while (q--) {
            int s, t;
            scanf ( "%d%d", &s, &t );
            printf ( "%lld\n", queryAsk( s, t ) );
        }

    }


    return 0;
}

















