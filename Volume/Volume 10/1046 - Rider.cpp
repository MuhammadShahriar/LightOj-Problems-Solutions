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

char c[12][12];
int n, m;
int lev[12][12];

void bfs ( int x, int y )
{
	queue<pii> q;
	mem ( lev, -1 );
	lev[x][y] = 0;
	q.push( {x, y} );

	while ( !q.empty() ) {
		x = q.front().F;
		y = q.front().S;
		q.pop();

		vii v = { {x+1, y+2}, {x+1, y-2}, {x+2, y+1}, {x+2, y-1}, {x-1, y+2}, {x-1, y-2}, {x-2, y+1}, {x-2, y-1} };

		for ( auto u : v ) {
			int x1 = u.F;
			int y1 = u.S;

			if ( x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && lev[x1][y1] == -1 ) {
				lev[x1][y1] = lev[x][y] + 1;
				q.push ( { x1, y1 } );
			}
		}
	}

}

int main()
{

	int T;
	scanf ( "%d", &T );

	for ( int tc = 1; tc <= T; tc++ ) {

		int ans = 0;
		scanf ( "%d%d", &n, &m );
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				cin >> c[i][j];
				if ( isdigit(c[i][j]) ) ans = inf;
			}
		}

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				int d = 0;
				bool done = 1;
				bfs ( i, j );

				for ( int l = 0; l < n; l++ ) {
					for ( int r = 0; r < m; r++ ) {
						if ( isdigit( c[l][r] ) ) {

							if ( lev[l][r] != -1 ) {
								int num = c[l][r] - '0';
								d  += ( lev[l][r] / num );
								if ( lev[l][r] % num ) d++;
							}
							else done = 0;
						}
					}
				}

				if ( done ) ans = min ( ans, d );
			}
		}



		if ( ans == inf ) ans = -1;
		printf ( "Case %d: %d\n", tc, ans );
	}


	return 0;
}

















