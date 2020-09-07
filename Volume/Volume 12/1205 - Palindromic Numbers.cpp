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

ll dp[20][3][3];
vi v;
int n;

ll solve ( int i, int f1, int f2 )
{
    if ( i >= n ) return (f2 > 0);
    if ( dp[i][f1][f2] != -1 ) return dp[i][f1][f2];
    ll ret = 0;

    for ( int j = 0; j < 10; j++ ) {
        if ( !f1 && v[i] < j ) continue;
        ret += solve ( i+1, f1 || ( j < v[i] ), f2 || ( j != 0 ) );
    }

    return dp[i][f1][f2] = ret;
}

ll getAns ( ll val )
{
    mem ( dp, -1 );
    ll ret = 0;
    if ( val != 0 ) ret++;
    else return 1;

    string s, tmp;
    v.clear();

    while ( val > 0 ) {
        s += ( ( val % 10 ) + '0' );
        v.PB ( val % 10 );
        val /= 10;
    }

    reverse( all ( v ) );
    reverse( all ( s ) );
    tmp = s;
    for ( int i = 0, j = sz(s)-1; i < ( sz (s) )/2; i++, j-- ) {
        tmp[j] = tmp[i];
    }
    n = ( sz ( v ) / 2 ) + ( sz ( v ) % 2 );
    for ( int i = 1; i <= v[0]; i++ ) ret += solve ( 1, ( i < v[0] ), 1 );

    if ( tmp > s ) ret--;
    for ( int i = 1; i < sz(v); i++ ) {
        n = ( i / 2 ) + ( i % 2 );
        ll d = 9;
        for ( int j = 2; j <= n; j++ ) d *= 10;
        ret += d;
    }

    return ret;
}

int main()
{

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        ll l, r;
        scanf ( "%lld%lld", &l, &r );
        if ( l > r ) swap( l, r );
        if ( l == 0 ) printf ( "Case %d: %lld\n", tc, getAns ( r ) );
        else printf ( "Case %d: %lld\n", tc, getAns ( r ) - getAns ( l-1 ) );
    }

    return 0;
}

















