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

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const int mx = 26;
int dp[mx][(1<<16)+123], Sz, dist[mx][mx][mx][mx], lev[mx][mx];
char c[mx][mx];
int gX[mx], gY[mx];

int solve ( int x, int mask )
{
    if ( mask == ( 1 << Sz ) - 1 ) return max ( abs ( gX[0] - gX[x] ), abs( gY[0] - gY[x] ) );
    if ( dp[x][mask] != -1 ) return dp[x][mask];

    int ans = inf;
    for ( int i = 0; i < Sz; i++ ) {
        if ( ( ( 1 << i ) & mask ) == 0 ) {
            ans = min ( ans, max ( abs ( gX[i] - gX[x] ), abs( gY[i] - gY[x] ) ) + solve ( i, mask | ( 1 << i ) ) );
        }
    }

    return dp[x][mask] = ans;
}


int main()
{

    int t;
    scanf ( "%d", &t );

    for ( int tc = 1; tc <= t; tc++ ) {

        mem ( dp, -1 );

        int x, y, n, m;
        scanf ( "%d%d", &n, &m );



        int cnt = 1;
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= m; j++ ) {

                scanf ( " %c", &c[i][j] );
                if ( c[i][j] == 'x' ) {
                    gX[0] = i;
                    gY[0] = j;
                }

                if ( c[i][j] == 'g' ) {
                    gX[cnt] = i;
                    gY[cnt++] = j;
                }
            }
        }

        Sz = cnt;

        int ans = solve ( 0, 0 );

        printf ( "Case %d: %d\n", tc, ans );
    }


    return 0;
}

















