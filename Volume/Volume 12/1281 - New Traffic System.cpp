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

const int mx = 1e4+123;

struct info {
    int v, w, typ;
    info ( int v, int w, int typ ) : v(v), w(w), typ(typ) {}
};

vector<info> adj[mx];
int Dist[15][mx], d;


void dijkstra( int s, int n )
{
    for ( int j = 0; j <= d; j++ ) {
        for(int i = 0; i <= n; i++) Dist[j][i] = inf;
    }

    for ( int i = 0; i <= d; i++ ) Dist[i][s] = 0;
    priority_queue<vi,vector<vi>,greater<vi>> q;
    q.push({0,0,s});

    while( !q.empty() ) {

        vi p = q.top();
        q.pop();

        int u = p[2], dist = p[0], cnt = p[1];
        if( dist > Dist[cnt][u] ) continue;

        for( info pr : adj[u] ) {
            int v = pr.v;
            int next_dist = dist + pr.w;

            if ( pr.typ == 1 ) {
                if( cnt + 1 <= d && next_dist < Dist[cnt+1][v]) {
                    Dist[cnt+1][v] = next_dist;
                    q.push( { next_dist, cnt+1, v } );
                }
            }
            else {
                if( next_dist < Dist[cnt][v]) {
                    Dist[cnt][v] = next_dist;
                    q.push( { next_dist, cnt, v } );
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < mx; i++ ) adj[i].clear();

        int n, m, k;
        scanf ( "%d%d%d%d", &n, &m, &k, &d );

        for ( int i = 1; i <= m; i++ ) {
            int u, v, w;
            scanf ( "%d%d%d", &u, &v, &w );
            u++, v++;
            adj[u].PB ( info ( v, w, 0 ) );
        }

        for ( int i = 1; i <= k; i++ ) {
            int u, v, w;
            scanf ( "%d%d%d", &u, &v, &w );
            u++, v++;
            adj[u].PB ( info ( v, w, 1 ) );
        }

        dijkstra( 1, n );

        int ans = inf;

        for ( int i = 0; i <= d; i++ ) ans = min ( ans, Dist[i][n] );

        if ( ans != inf ) printf ( "Case %d: %d\n", tc, ans );
        else printf ( "Case %d: Impossible\n", tc );
    }


    return 0;
}
















