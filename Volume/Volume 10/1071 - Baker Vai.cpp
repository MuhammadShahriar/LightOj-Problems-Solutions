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

const int mx = 123;
int dp[mx][mx][mx][3];
int a[mx][mx], n, m;
int sum[mx][mx];

vi v[mx][23];

int solve ( int i, int j, int k, int f1 )
{
	if ( i == n-1 && j == m-1 ) {
		int ret = 0;
		if ( f1 == 0 ) return -1000000;
		return sum[n][j] - sum[k][j];
	}

	if ( n == i || m == j ) return -1000000;
	if ( dp[i][j][k][f1] != -1 ) return dp[i][j][k][f1];

	int ret = 0;
	if ( !f1 ) {
		ret = a[i][j] + max ( solve ( i+1, j, k, 0 ), solve ( i, j+1, k, 1 ) );
	}
	else {
		for ( int l = k; l < i; l++ ) {
			ret = max ( ret, sum[l+1][j] - sum[k][j] + a[i][j] + max ( solve ( i+1, j, l, 0 ), solve ( i, j+1, l, 1 ) ) );
		}
	}

	return dp[i][j][k][f1] = ret;
}



int main()
{
	int T;
	scanf ( "%d", &T );

	for ( int tc = 1; tc <= T; tc++ ) {
		cin >> n >> m;

		for ( int i = 0; i <= 100; i++ ) {
			for ( int j = 0; j <= 21; j++ ) v[i][j].clear();
		}

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				cin >> a[i][j];
				v[j][a[i][j]].PB ( i );
			}
		}

		for ( int i = 0; i < m; i++ ) {
			for ( int j = 0; j <= 20; j++ ) sort ( all ( v[i][j] ) );
		}

		mem ( sum, 0 );
		for ( int i = 0; i < m; i++ ) {
			for ( int j = 1; j <= n; j++ ) {
				sum[j][i] = sum[j-1][i] + a[j-1][i];
			}
		}

		mem ( dp, -1 );

		printf ( "Case %d: %d\n", tc, solve ( 0, 0, 0, 0 ) );
	}

	return 0;
}

















