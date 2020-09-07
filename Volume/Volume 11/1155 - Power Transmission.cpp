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

int n;
int a[mx];
int par[mx];

template <class flow_t> struct Dinic { //int/long long;
  const static bool SCALING = true; // non-scaling = V^2E, Scaling=VElog(U) with higher constant
  long long lim = 1;
  const flow_t INF = numeric_limits<flow_t>::max();
  flow_t K;
  bool K2 = false;
  struct edge {
    int to, rev;
    flow_t cap, flow, per_cap;
  };
  int s, t;
  vector<int> level, ptr;
  vector< vector<edge> > adj;
  Dinic(int NN) : s(NN-2), t(NN-1), level(NN), ptr(NN), adj(NN) {}
  void flow_limit( flow_t val ) { //non-maxflow upto K.
    K2 = true;
    K = val;
  }
  void addEdge(int a, int b, flow_t cap, bool isDirected = true) {
    adj[a].push_back({b, (int)adj[b].size(), cap, 0, cap});
    adj[b].push_back({a, (int)adj[a].size() - 1, isDirected ? 0 : cap, 0, isDirected ? 0 : cap});
  }
  bool bfs() {
    queue<int> q({s});
    fill( level.begin(), level.end(), -1 );
    level[s] = 0;
    while (!q.empty() && level[t] == -1) {
      int v = q.front();
      q.pop();
      for (auto e : adj[v]) {
        if (level[e.to] == -1 && e.flow < e.cap && (!SCALING || e.cap - e.flow >= lim)) {
          q.push(e.to);
          level[e.to] = level[v] + 1;
        }
      }
    }
    return level[t] != -1;
  }
  flow_t dfs(int v, flow_t flow) {
    if (v == t || !flow) return flow;
      for (; ptr[v] < adj[v].size(); ptr[v]++) {
        edge &e = adj[v][ptr[v]];
        if (level[e.to] != level[v] + 1) continue;
        if (flow_t pushed = dfs(e.to, min(flow, e.cap - e.flow))) {
          e.flow += pushed;
          adj[e.to][e.rev].flow -= pushed;
          return pushed;
        }
      }
    return 0;
  }
  flow_t max_flow(int source, int sink) {
    s = source, t = sink;
    long long flow = 0;
    for (lim = SCALING ? (1LL << 30) : 1; lim > 0; lim >>= 1) { //Here, lim = SCALING?(U):1 ; Here U is an int/long long strictly greater than the max capacity ;
      while (bfs()) {
        fill( ptr.begin(), ptr.end(), 0 );
        while (flow_t pushed = dfs(s, ((K2==true)?K:INF))) {
          flow += pushed;
          if(K2) {
            K -= pushed;
            if( K == 0 ) break;
          }
        }
        if( K2 && (K == 0) ) break;
      }
    }
    return flow;
  }
  vector<pair<pair<int,int>,long long>> getActualFlow() {
    vector<pair<pair<int,int>, long long>> vec;
    for( int i = 0; i < adj.size(); ++i ) {
      for( int j = 0; j < adj[i].size(); ++j ) {
        if( adj[i][j].flow > 0 ) {
          vec.push_back( make_pair(make_pair(i, adj[i][j].to), adj[i][j].flow) );
        }
      }
    }
    return vec;
  }
};

int main()
{
	//optimize();
	int T;
	cin >> T;
	for ( int tc = 1; tc <= T; tc++ ) {
		cin >> n;
		Dinic<int> f1(n*2+3);

		for ( int i = 1; i <= n; i++ ) cin >> a[i];
		for ( int i = 1; i <= n; i++ ) {
			par[i] = i+n;
			f1.addEdge ( i, i+n, a[i] );
		}

		int m;
		cin >> m;
		for ( int i = 0; i < m; i++ ) {
			int u, v, c;
			cin >> u >> v >> c;
			f1.addEdge( par[u], v, c );
		}

		int B, D;
		cin >> B >> D;

		for ( int i = 0; i < B; i++ ) {
			int u;
			cin >> u;
			f1.addEdge(0, u, inf);
		}

		for ( int i = 0; i < D; i++ ) {
			int u;
			cin >> u;
			f1.addEdge(par[u], n*2+1, inf);
		}

		n *= 2;

		printf ( "Case %d: %d\n", tc, f1.max_flow(0, n+1) );
	}






	return 0;
}
















