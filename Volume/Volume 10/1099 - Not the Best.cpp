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



const int mx = 5005;
int Dist[mx];
vii adj[mx];
int d1[mx], d2[mx];

void dijkstra( int s, int n )
{
    for(int i = 0; i <= n; i++) Dist[i] = inf;
    Dist[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});

    while( !q.empty() ) {

        pii p = q.top();
        q.pop();

        int u = p.S, dist = p.F;
        if( dist > Dist[u] ) continue;

        for( pii pr : adj[u] ) {
            int v = pr.F;
            int next_dist = dist + pr.S;

            if(next_dist < Dist[v]) {
                Dist[v] = next_dist;
                q.push( { next_dist,v } );
            }
        }
    }
}

struct info{
    int u, v, w;
    info ( int u, int v, int w ) : u(u), v(v), w(w){}
};

int main()
{

    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        for ( int i = 0; i < mx; i++ ) adj[i].clear();
        vector < info > edge;

        int n, m;
        scanf ( "%d%d", &n, &m );

        for ( int i = 1; i <= m; i++ ) {
            int u, v, w;
            scanf ( "%d%d%d", &u, &v, &w );

            adj[u].PB ( { v, w } );
            adj[v].PB ( { u, w } );
            edge.PB ( info ( u, v, w ) );
        }

        dijkstra( 1, n );
        for ( int i = 1; i <= n; i++ ) d1[i] = Dist[i];
        int path = Dist[n];
        int ans = inf;

        dijkstra( n, n );
        for ( int i = 1; i <= n; i++ ) d2[i] = Dist[i];

        for ( auto u : edge ) {
            int d = min ( d1[u.u] + d2[u.v] + u.w, d1[u.v] + d2[u.u] + u.w );
            if ( d == path ) {
                ans = min ( ans, d + (2*u.w) );
            }
            else if ( d > path ) {
                ans = min  ( ans, d );
            }
        }

        printf ( "Case %d: %d\n", tc, ans );
    }


    return 0;
}

















