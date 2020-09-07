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


const int mx = 512;
dl dp[mx][mx][4];

dl solve ( int b, int r, int f1 )
{
    if ( b == 0 ) return 0;
    if ( r == 0 ) return 1;

    if ( dp[b][r][f1] != -1 ) return dp[b][r][f1];

    dl ret = 0;

    if ( f1 == 1 ) ret = ( ( (dl) b / (dl) (r+b) ) * solve ( b-1, r, 2 ) ) + ( ( (dl) r / (dl) (r+b) ) * solve ( b, r-1, 2 ) );
    else ret = solve ( b-1, r, 1 );

    return dp[b][r][f1] = ret;
}


int main()
{
    optimize();

    for ( int i = 0; i <= 500; i++ ) {
        for ( int j = 0; j <= 500; j++ ) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
    }


    int t;
    scanf ( "%d", &t );

    for ( int tc = 1; tc <= t; tc++ ) {
        int r, b;
        scanf ( "%d%d", &r, &b );
        printf ( "Case %d: %.10f\n", tc, solve ( b, r, 1 ) );
    }


    return 0;
}

















