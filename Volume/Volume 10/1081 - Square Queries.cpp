///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**

Just create sparse table for each dimension of the gird. And make query.

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

const int mx = 500+123;
int st[mx][mx][25], a[mx][mx];

void preprocess ( int n, int id )
{
    for ( int i = 1; i <= n; i++ ) st[id][i][0] = a[id][i];

    for ( int i = 1; i <= 24; i++ ) {
        for ( int j = 1; j + ( 1 << (i-1) ) <= n; j++ ) {
            st[id][j][i] = max ( st[id][j][i-1], st[id][j+(1<<(i-1))][i-1] );
        }
    }
}

int query ( int l, int r, int id )
{
    int lg = log2( r - l + 1 );
    return max ( st[id][l][lg], st[id][r-(1<<lg)+1][lg] );
}

int main()
{


    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        int n, q;
        scanf ( "%d%d", &n, &q );

        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= n; j++ ) scanf ( "%d", &a[i][j] );
        }

        for ( int i = 1; i <= n; i++ ) {
            preprocess( n, i );
        }

        printf ( "Case %d:\n", tc );
        while ( q-- ) {
            int l1, r1, l2, r2, d;
            scanf ( "%d%d%d", &l1, &r1, &d );
            l2 = l1 + d - 1;
            r2 = r1 + d - 1;

            int ans = 0;
            for ( int i = l1; i <= l2; i++ ) {
                ans = max ( ans, query ( r1, r2, i ) );
            }

            printf ( "%d\n", ans );
        }
    }


    return 0;
}

















