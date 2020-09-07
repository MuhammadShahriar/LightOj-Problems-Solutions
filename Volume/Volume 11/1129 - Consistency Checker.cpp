///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**
Normal trie.
Just check if there is any edge from leaf of any string. And also check that is any edge staring from a leaf.

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

const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);

bool no;

void add_string(string const& s)
{
    int v = 0;
    for ( char ch : s ) {
        int c = ch - '0';
        if ( trie[v].next[c] == -1 ) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }

        v = trie[v].next[c];
        if ( trie[v].leaf ) no = 0;
    }

    trie[v].leaf = true;
    for ( int i = 0; i < 10; i++ ) if ( trie[v].next[i] != -1 ) no = 0;
}

int main()
{
    int T;
    scanf ( "%d", &T );

    for ( int tc = 1; tc <= T; tc++ ) {
        trie.clear();
        trie.emplace_back();

        no = 1;
        int n;
        scanf ( "%d", &n );
        for ( int i = 1; i <= n; i++ ) {
            char str[12];
            scanf ( "%s", str );
            int len = strlen(str);

            string s;
            for ( int i = 0; i < len; i++ ) s += str[i];

            add_string( s );
        }

        if ( no ) printf ( "Case %d: YES\n", tc );
        else printf ( "Case %d: NO\n", tc );

    }

    return 0;
}

















