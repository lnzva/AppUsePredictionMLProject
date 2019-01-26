#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
using namespace std;
using namespace __gnu_pbds;

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

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;

//#define PB push_back
#define PB emplace_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define pf printf
#define sf scanf
#define left __left
#define right __right
#define tree __tree

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

/*
bool seive[1010000];
vi prime;

void seiveGen(int limit) {
    limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
            if(!seive[i>>1]) {
                    for(int j = i * i; j < limit; j += i + i) {
                            seive[j>>1] = 1;
                    }
            }
    }
    prime.PB(2);
    for(int i = 3; i < limit; i += 2) {
            if(!seive[i>>1]) prime.PB(i);
    }
}
*/

//
//debug
#ifdef yamin
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
            cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}
#else
#define dbg(args...)
#endif // yamin

vector<vector<string> > transactions;
vector<string> labels;
set<string> storelol[10];

void input() {
	ifstream fin("1404001_2018-10-28.csv");

	if (!fin) {
		cerr << "ERR";
	}

	string s;
	getline(fin, s);

	set<string> p_store;

	while (getline(fin, s)) {
		vector<string> tmp;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '"') {
				string t;
				++i;
				while (s[i] != '"') {
					t += s[i];
					++i;
				}
				tmp.push_back(t);
			}
		}
		p_store.insert(tmp.back());
		for (int i = 0; i < tmp.size(); ++i) {
			storelol[i].insert(tmp[i]);
		}
		transactions.push_back(tmp);
	}

	for (auto s : p_store)
		labels.PB(s);

}

string classify(vector<string> input) {
	string ret;
	long double max_result = 0;
	for (auto label : labels) {
		vector<int> store;
		store.resize(input.size() - 1);
		long double cur_result = 1;
		int yes_cnt = 0;
		for (int i = 0; i < transactions.size(); ++i) {
			if (transactions[i].back() == label) {
				++yes_cnt;
				for (int j = 0; j < input.size() - 1; ++j) {
					if (input[j] == transactions[i][j])
						++store[j];
				}
			}
		}
		for (int i = 0; i < store.size(); ++i)
			cur_result *= (double)(store[i] + 1) / (double)(yes_cnt + storelol[i].size());
		
		cur_result *= (double)(yes_cnt) / (double)(transactions.size());

		if (cur_result >= max_result) {
			max_result = cur_result;
			ret = label;
		}
	}

	return ret;
}

int main() {
	input();

	int cnt = 0;
	for (int i = 0; i < transactions.size(); ++i) {
		cout << classify(transactions[i]) << endl;
		if (transactions[i].back() == classify(transactions[i]))
			++cnt;
	}
	cout << (double)cnt / (double)transactions.size() * 100.0 << endl;
}