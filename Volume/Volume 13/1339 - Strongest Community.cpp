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
			st[j][i] = max ( st[j][i-1], st[j+(1<<(i-1))][i-1] );
		}
	}
}

int query ( int l, int r )
{
	int lg = log2( r - l + 1 );
	return max ( st[l][lg], st[r-(1<<lg)+1][lg] );
}

int b[mx];
int cnt[mx];
int first[mx], last[mx];

int nxt ()
{
    int in;
    scanf ( "%d", &in );
    return in;
}

int main()
{

	int t = nxt();
	for ( int tc = 1; tc <= t; tc++ ) {
        mem ( cnt, 0 );
        int n = nxt (), c = nxt(), q = nxt();


        for ( int i = 1; i <= n; i++ ) {
            b[i] = nxt();
            cnt[b[i]]++;
        }

        for ( int i = 1; i <= n; i++ ) last[b[i]] = i;
        for ( int i = n; i >= 1; i-- ) first[b[i]] = i;

        for ( int i = 1; i <= n; i++ ){
            a[i] = cnt[b[i]];
        }
        preprocess ( n );

        printf ( "Case %d:\n", tc );
        while ( q-- ) {
            int l = nxt(), r = nxt();
            int ans = 0;
            if ( r+1 <= n && b[r] == b[r+1] ) {
                ans = max ( ans, r - max ( l, first[b[r]] ) + 1 );
                r = first[b[r]]-1;
            }

            if ( l-1 >= 1 && b[l] == b[l-1] ) {
                ans = max ( ans, min (r, last[b[l]]) - l + 1 );
                l = last[b[l]]+1;
            }


            if ( l <= r ) ans = max ( ans, query ( l, r ) );

            printf ( "%d\n", ans );
        }
	}


	return 0;
}

















