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

map<string, vector<string> > adj;
map<string, int> lev;
map<string, bool > forbid;


void bfs ( string s )
{
	lev.clear();
	queue<string> q;

	if ( !forbid[s] ) {
		lev[s] = 1;
		q.push ( s );
	}

	while ( !q.empty() ) {
		s = q.front();
		q.pop();

		for ( int i = 0; i < 3; i++ ) {
			int d = s[i] - 'a';
			d++;
			d %= 26;
			string u = s;
			u[i] = (char) (d + 'a');

			if ( lev[u] == 0 && !forbid[u] ) {
				lev[u] = lev[s] + 1;
				q.push ( u );
			}

			d = s[i] - 'a';
			d--;
			if ( d < 0 ) d = 25;
			u = s;
			u[i] = (char) (d + 'a');

			if ( lev[u] == 0 && !forbid[u] ) {
				lev[u] = lev[s] + 1;
				q.push ( u );
			}
		}
	}
}


int main()
{
	optimize();

	int t;
	cin >> t;

	for ( int tc = 1; tc <= t; tc++ ) {
		string st, fh;
		cin >> st >> fh;
		forbid.clear();
		adj.clear();

		int n;
		cin >> n;

		for ( int i = 0; i < n; i++ ) {
			string s1, s2, s3;
			cin >> s1 >> s2 >> s3;

			for ( int i = 0; i < sz(s1); i++ ) {
				for ( int j = 0; j < sz ( s2 ); j++ ) {
					for ( int k = 0; k < sz ( s3 ); k++ ) {
						string s;
						s += s1[i];
						s += s2[j];
						s += s3[k];
						forbid[s] = 1;
					}
				}
			}
		}

		if ( sz ( st ) < 3  ) {
			int ans = 0;

			for ( int i = 0; i < sz ( st ); i++ ) {
				char c1 = st[i], c2 = fh[i];
				if ( c1 > c2 ) swap ( c1, c2 );


				int d1 = c2 - c1;
				int d2 = ( 'z' - c2 ) + ( c1 - 'a' ) + 1;
				ans += min ( d1, d2 );
			}

			cout << "Case " << tc << ": " << ans << endl;
			continue;
		}

		int ans = 0;

		for ( int i = 3; i < sz ( st ); i++ ) {
			char c1 = st[i], c2 = fh[i];
			if ( c1 > c2 ) swap ( c1, c2 );


			int d1 = c2 - c1;
			int d2 = ( 'z' - c2 ) + ( c1 - 'a' ) + 1;
			ans += min ( d1, d2 );
		}

		string source, dist;
		source += st[0];
		source += st[1];
		source += st[2];

		dist += fh[0];
		dist += fh[1];
		dist += fh[2];


		bfs(source);

		if ( lev[dist] != 0 ) {
			cout << "Case " << tc << ": " << ans + lev[dist]-1 << endl;
		}
		else cout << "Case " << tc << ": " << "-1" << endl;
	}


	return 0;
}

















