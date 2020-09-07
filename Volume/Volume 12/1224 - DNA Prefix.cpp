///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**

Simple trie.
While updating string in trie count how many times a single node has visited.
Ans is max ( len * cnt[N] ).
Here N is the node number. cnt[N] is how many times N is accessed. len is string prefix length which ends in node N.

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



struct Vertex {
    int next[4], cnt = 0;
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

int ans = 0;

void add_string(string const& s)
{
    int v = 0;
    int len = 0;
    for ( char ch : s ) {
        len++;
        int c;
        if ( 'A' == ch ) c = 0;
        if ( 'T' == ch ) c = 1;
        if ( 'G' == ch ) c = 2;
        if ( 'C' == ch ) c = 3;
        if ( trie[v].next[c] == -1 ) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }

        v = trie[v].next[c];
        trie[v].cnt++;
        ans = max ( ans, trie[v].cnt * len );
    }

    trie[v].leaf = true;
}
char str[60];
int main()
{
    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        trie.clear();
        trie.emplace_back();

        ans = 0;
        int n;
        scanf ( "%d", &n );
        for ( int i = 1; i <= n; i++ ) {

            scanf ( "%s", str );
            int len = strlen(str);

            string s;
            for ( int i = 0; i < len; i++ ) s += str[i];

            add_string( s );
        }

        printf ( "Case %d: %d\n", tc, ans );

    }

    return 0;
}

















