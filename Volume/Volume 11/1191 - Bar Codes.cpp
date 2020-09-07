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

const int mx = 53;

ll dp[mx][mx][mx];

ll solve ( int i, int j, int lim )
{
	if ( i == 0 || j == 0 ) return ( i == 0 && j == 0 );
	if ( dp[i][j][lim] != -1 ) return dp[i][j][lim];

	ll ret = 0;
	for ( int k = lim; k >= 1; k-- ) {
		if ( i - k >= 0 ) ret += solve ( i-k, j-1, lim );
	}

	return dp[i][j][lim] = ret;
}


int main()
{

	int T;
	scanf ( "%d", &T );

	mem ( dp, -1 );
	for ( int tc = 1; tc <= T; tc++ ) {
		int n, k, m;
		scanf ( "%d%d%d", &n, &k, &m );
		printf ( "Case %d: %lld\n", tc, solve ( n, k, m ) ) << endl;
	}

	return 0;
}

















