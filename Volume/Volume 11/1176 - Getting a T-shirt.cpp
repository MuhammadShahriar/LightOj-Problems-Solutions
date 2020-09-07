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

//Complexity: O(sqrt(V) * E), constant may be a bit high.
//Works on self loops.
struct Hopcroft_karp {
  int n;
  vector< vector<int> > edge;
  vector<int> dis, parent, L, R;
  vector<int> Q;
  Hopcroft_karp(int n_) : n(n_), edge(n_+1), dis(n_+1), parent(n_+1), L(n_+1), R(n_+1), Q(n_+1) {};
  void add_edge( int u, int v ) {
    edge[u].push_back(v);
  }
  bool dfs(int i) {
    int len = edge[i].size();
    for (int j = 0; j < len; j++) {
      int x = edge[i][j];
      if (L[x] == -1 || (parent[L[x]] == i)) {
        if (L[x] == -1 || dfs(L[x])) {
          L[x] = i;
          R[i] = x;
          return (true);
        }
      }
    }
    return false;
  }
  bool bfs() {
    int x, f = 0, l = 0;
    fill( dis.begin(), dis.end(), -1 );
    for (int i = 1; i <= n; i++) {
      if (R[i] == -1) {
        Q[l++] = i;
        dis[i] = 0;
      }
    }
    while (f < l) {
      int i = Q[f++];
      int len = edge[i].size();
      for (int j = 0; j < len; j++) {
        x = edge[i][j];
        if (L[x] == -1) return true;
        else if (dis[L[x]] == -1) {
          parent[L[x]] = i;
          dis[L[x]] = dis[i] + 1;
          Q[l++] = L[x];
        }
      }
    }
    return false;
  }
  int matching() {
    int counter = 0;  //How many nodes are part of the maximum matching?
    fill( L.begin(), L.end(), -1 );
    fill( R.begin(), R.end(), -1 );
    while (bfs()) {
      for (int i = 1; i <= n; i++) {
        if (R[i] == -1 && dfs(i)) counter++;
      }
    }
    return counter;
  }
};

int main()
{
	optimize();

	map<string, int> col;
	col["M"] = 1;
	col["S"] = 2;
	col["XS"] = 3;
	col["XL"] = 4;
	col["XXL"] = 5;
	col["L"] = 6;

	int T;
	cin >> T;
	for ( int tc = 1; tc <= T; tc++ ) {
		int n, m;
		cin >> n >> m;
		Hopcroft_karp h( (n*6)+m );

		int id = 6*n;
		int tmp =m;
		while ( m-- ) {
			string s1, s2;
			cin >> s1 >> s2;

			int u, v;
			u = ( (col[s1]-1) * n );
			v = ++id;

			//dbg(u, v);
			for ( int i = 1; i <= n; i++ ) {
				h.add_edge ( u+i, v );
			}

			u = ( (col[s2]-1) * n );

			for ( int i = 1; i <= n; i++ ) {
				h.add_edge ( u+i, v );
			}
		}

		m=tmp;
		string ans;
		if ( h.matching() == m ) ans = "YES";
		else ans = "NO";

		cout << "Case " << tc << ": " << ans << endl;

	}


	return 0;
}
















