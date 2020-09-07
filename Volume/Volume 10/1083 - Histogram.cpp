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


const int mx = 1e5+123;
int st[mx][25], a[mx];

void preprocess ( int n )
{
	for ( int i = 1; i <= n; i++ ) st[i][0] = a[i];

	for ( int i = 1; i <= 24; i++ ) {
		for ( int j = 1; j + ( 1 << (i-1) ) <= n; j++ ) {
			st[j][i] = min ( st[j][i-1], st[j+(1<<(i-1))][i-1] );
		}
	}
}

int query ( int l, int r )
{
	int lg = log2( r - l + 1 );
	return min ( st[l][lg], st[r-(1<<lg)+1][lg] );
}


int main()
{
	optimize();

	int t;
	cin >> t;
	for ( int tc = 1; tc <= t; tc++ ) {
        int n;
        cin >> n;
        for ( int i = 1; i <= n; i++ ) cin >> a[i];
        preprocess ( n );

        ll ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            int l = 1, r = i;
            int id1 = i, id2 = i;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;

                if ( query ( mid, i ) >= a[i] ) {
                    id1 = mid;
                    r = mid-1;
                }
                else l = mid+1;
            }

            l = i, r = n;
            while ( l <= r ) {
                int mid = ( l + r ) >> 1;

                if ( query ( i, mid ) >= a[i] ) {
                    id2 = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }

            ans = max ( ans, 1LL * (id2-id1+1) * a[i] );
        }

        cout << "Case " << tc << ": " << ans << endl;
	}


	return 0;
}

















