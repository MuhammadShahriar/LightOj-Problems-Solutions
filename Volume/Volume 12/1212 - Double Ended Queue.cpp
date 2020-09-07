///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///


/**
Just use normal deque.
**/


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

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

int main()
{
    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        int n, m;
        scanf ( "%d%d", &n, &m );

        deque < int > q;
        printf ( "Case %d:\n", tc );

        while ( m-- ) {

            string a;
            cin >> a;

            if ( a == "pushLeft" ) {
                int v;
                scanf( "%d", &v );
                if ( q.size() == n ) printf ( "The queue is full\n" );
                else {
                    printf ( "Pushed in left: %d\n", v );
                    q.push_front( v );
                }
            }

            if ( a == "pushRight" ) {
                int v;
                scanf( "%d", &v );
                if ( q.size() == n ) printf ( "The queue is full\n" );
                else {
                    printf ( "Pushed in right: %d\n", v );
                    q.push_back( v );
                }
            }

            if ( a == "popLeft" ) {
                if ( q.empty() ) printf ( "The queue is empty\n" );
                else {
                    printf ( "Popped from left: %d\n", q.front() );
                    q.pop_front();
                }
            }

            if ( a == "popRight" ) {
                if ( q.empty() ) printf ( "The queue is empty\n" );
                else {
                    printf ( "Popped from right: %d\n", q.back() );
                    q.pop_back();
                }
            }

        }
    }

    return 0;
}
















