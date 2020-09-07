///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
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
#define MOD ( 1LL << 32 )

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


#define mx 100001010
long long a[mx / 64 + 200];
int prime[5800000];
int cnt = 0;
ui sum[5861558];


void sieveGen( int limit )
{
    limit += 100;
    int sq = sqrt ( limit );

	for (long long i = 3; i <= sq; i += 2) {
		if(!(a[i/64]&(1LL<<(i%64)))) {
			for(long long j = i * i; j <= limit; j += 2 * i) {
				a[j/64] |= (1LL<<(j%64));
			}
		}
	}

	prime[cnt++] = 2;
	for (long long i = 3; i <= limit; i += 2) {
		if(!(a[i / 64] & (1LL << (i % 64)))) {
			prime[cnt++] = i;
		}

	}

}


int main()
{
    sieveGen( 1e8 );

    sum[0] = 1;
    for ( int i = 0; i < cnt; i++ ) {
        sum[i+1] = sum[i] * prime[i];
    }

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        int n;
        scanf ( "%d", &n );

        ui ans = 1;
        int id = upper_bound( prime, prime+cnt, n ) - prime;
        ui mul = sum[id];

        for ( int i = 0; i < cnt; i++ ) {
            ll u = prime[i];
            if ( u*u > n ) break;
            ll p = u;

            while ( p*u <= n ) {
                ans = ans * u;
                p *= u;
            }
        }

        ans *= mul;

        printf ( "Case %d: %lu\n", tc, ans );
    }



    return 0;
}

















