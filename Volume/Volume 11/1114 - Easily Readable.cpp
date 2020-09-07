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

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }



string make_string ( string const &s )
{
    int len = sz( s );
    if ( len == 1 ) return s;
    string ret, tmp = "";

    ret += s[0];
    ret += s[len-1];

    for ( int i = 1; i < len-1; i++ ) tmp += s[i];
    sort ( all ( tmp ) );
    ret += tmp;

    return ret;
}

int main()
{

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {

        int n;
        scanf ( "%d", &n );
        map <string , int > cnt;

        for ( int i = 1; i <= n; i++ ) {
            string s;
            char c;
            cin >> c;
            getline( cin, s );
            s = c + ( s[0] == '\n' ? "" : s );
            cnt[make_string(s)]++;
        }

        int m;
        scanf ( "%d", &m );
        cin.get();

        printf ( "Case %d:\n", tc );
        while ( m-- ) {
            int ans = 1;
            string s, str;
            char c1, c2;
            c1 = cin.get();

            if ( c1 == '\n' ) {
                printf ( "1\n" );
                continue;
            }

            getline( cin, str );
            str = c1 + str;


            int len = sz ( str );
            for ( int i = 0; i < len; i++ ) {
                if ( isspace( str[i] ) ) {
                    if ( sz ( s ) == 0 ) continue;
                    ans *= cnt[make_string(s)];
                    s.clear();
                    continue;
                }

                 s += str[i];
            }

            if ( sz ( s ) > 0 ) ans *= cnt[make_string(s)];

            printf ( "%d\n", ans );
        }


    }




    return 0;
}

















