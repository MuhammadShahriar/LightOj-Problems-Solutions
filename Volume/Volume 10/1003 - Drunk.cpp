///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///


/**

Just create a graph using given strings as node. Now find if there any cycle exist or not. If cycle exist print "No", otherwise "Yes".

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



const int mx = 1e4+123;

vi adj[mx];
int color[mx];
int parent[mx];
int cycle_start, cycle_end;

bool dfs(int v, int p) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0 ) {
            parent[u] = v;
            if (dfs(u, v))
                return true;
        } else if (  color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int find_cycle( int n )
{
    for ( int i = 0; i <= n; i++ ) {
        parent[i] = -1;
        color[i] = 0;
    }
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v, 0))
            break;
    }

    return ( cycle_start != -1 );
}

char str[20];

int main()
{

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {

        for ( int i = 0; i < mx; i++ ) adj[i].clear();

        int n;
        scanf ( "%d", &n );
        int cnt = 0;

        vector < pair < string, string > > edge;
        map < string, int > id;
        set < string > s;

        for ( int i = 1; i <= n; i++ ) {
            string s1, s2;
            scanf ( " %s", str );
            int d = strlen( str );
            for ( int i = 0; i < d; i++ ) s1 += str[i];

            scanf ( " %s", str );
            d = strlen( str );
            for ( int i = 0; i < d; i++ ) s2 += str[i];

            edge.PB ( { s1, s2 } );
            s.insert ( s1 );
            s.insert ( s2 );
        }


        for ( auto u : s ) {
            id[u] = ++cnt;
        }

        for ( auto u : edge ) {
            adj[id[u.F]].PB ( id[u.S] );
        }


        if ( find_cycle(cnt) ) printf ( "Case %d: No\n", tc );
        else printf ( "Case %d: Yes\n", tc );
    }


    return 0;
}

















