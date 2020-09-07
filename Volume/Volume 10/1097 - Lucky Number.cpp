///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

/**

Topic : Policy based data structure, hermonic series, prime counting function.
Complexity : Less than O(n*ln(n)*log2(n)).

Using prime counting function you can easily proof that you don't need to iterate greater than 1.5 * 10^6 numbers
for generating first 100000 lucky numbers. Use bellow inequality :
    ( x / ln(x) ) <= number of primes up to x <= 1.25506 * ( x / ln(x) )

Now we will generate first 100000 lucky numbers in a set. Actually greater than 100000. We will use policy based
data structure as set. If you use policy based data structure as set you can get the k-th element of your set.
Now question is how could we get first 100000 lucky numbers in our set? Just put all odd numbers from 1 to 1.5*10^6 in set.
Now get first element of the set and generate all its multiples p and erase p-th elements is the set. You can do it easily
using policy based data structure. Now for 2nd element of the set do the same. Than for 3-rd, 4-th and so on.
In this way we can generate first 100000 lucky numbers in our set in less than O(n*ln(n)*log2(n)) complexity.

Complexity can be proofed using hermonic series.
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


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

void erase ( ordered_set &s, int val )
{
    auto it = s.upper_bound(val);

    if ( it == s.begin() && val == *s.begin() ) s.erase ( s.upper_bound(val) );
    else s.erase ( s.upper_bound(val) );
}

/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element ( 0-based )
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item



int main()
{
    ordered_set s;

    int l = 1.5e6;
    for ( int i = 1; i <= l; i += 2 ) s.insert ( i );
    int cnt = 1;

    for ( ;cnt <= 100000; ) {
        int st = *s.find_by_order(cnt++);
        int c = 0;
        vi v;
        for ( int j = st; j <= l; j += st ) {
            if ( sz ( s ) < j ) continue;
            int d = *s.find_by_order(j-1);
            v.PB ( d );
        }

        for ( auto u : v ) erase( s, u );
    }

    int T;
    scanf ( "%d", &T );
    for ( int tc = 1; tc <= T; tc++ ) {
        int n;
        scanf ( "%d", &n );
        printf ( "Case %d: %d\n", tc, *s.find_by_order(n-1) );
    }

    return 0;
}

















