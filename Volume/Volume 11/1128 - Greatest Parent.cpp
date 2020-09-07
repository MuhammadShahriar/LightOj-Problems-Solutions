///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



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
void faltu () {			cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

const int mx = 1e5+123;
int P[mx][30], parent[mx], level[mx];
int val[mx];
vi adj[mx];

inline void dfs_for_LCA ( int u, int lev )
{
	level[u] = lev;
	for ( auto v : adj[u] ) {
		if ( v != parent[u] ) {
			parent[v] = u;
			dfs_for_LCA( v, lev+1 );
		}
	}
}

inline void preprocess ( int n )
{
	mem ( P, -1 );

	for ( int i = 1; i <= n; i++ ) P[i][0] = parent[i];

	for ( int j = 0; ( 1 << j ) <= n; j++ ) {
		for ( int i = 1; i <= n; i++ ) {
			if ( P[i][j-1] != -1 ) {
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
	}
}

int nxt ()
{
    int n;
    scanf ( "%d", &n );
    return n;
}

int main()
{

	int t = nxt();
	for ( int tc = 1; tc <= t; tc++ ) {
        for ( int i = 0; i < mx; i++ ) adj[i].clear();
        int n = nxt(), q = nxt();

        val[1] = 1;
        for ( int i = 2; i <= n; i++ ) {
            int p = nxt(), s = nxt();
            p++;
            adj[i].PB ( p );
            adj[p].PB ( i );
            val[i] = s;
        }

        dfs_for_LCA ( 1, 0 );
        preprocess ( n );

        printf ( "Case %d:\n", tc );

        while ( q-- ) {
            int k = nxt(), v = nxt();

            int l = 1, r = level[k+1];
            int ans = k+1;

            while ( l <= r ) {
                int mid = ( l + r ) >> 1;
                int dist = mid;
                int u = k+1;

                while ( dist > 0 ) {
                    int rise = log2( dist );
                    u = P[u][rise];
                    dist -= ( 1 << rise );
                }

                if ( val[u] >= v ) {
                    ans = min (ans, u);
                    l = mid+1;
                }
                else r = mid-1;
            }

            printf ( "%d\n", ans-1 );
        }
	}


	return 0;
}
















