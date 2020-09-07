///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**

This is simple ternary search problem. Make ternary search on T.
Be careful about N = 0. If N = 0 ans will be infinite so that time you have to print 0.

*/

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

ll n, c;
ll f ( ll t )
{
    if ( c < n * t ) return -1;
    return t * ( c - ( n * t ) );
}

int main()
{

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        scanf ( "%lld%lld", &n, &c );

        ll l = 0, r = 1e9+123;

        while ( l < r ) {
            ll m1 = l + ( r - l ) / 3;
            ll m2 = r - ( r - l ) / 3;

            if ( f ( m1 ) >= f ( m2 ) ) {
                r = m2-1;
            }
            else {
                l = m1+1;
            }
        }

        ll ans = l, d = f(l);
        for ( int i = l+1; i <= r; i++ ) {
            if ( f ( i ) > d ) {
                d = f ( i );
                ans = i;
            }
        }

        if ( ans == 1e9+123 ) ans = 0;

        printf ( "Case %d: %lld\n", tc, ans );
    }


    return 0;
}

















