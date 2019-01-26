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
vector<string> dictionary;
vector<vector<string> > L;
vector<vector<string> > frequent_set;

const double min_support = 0.5;
const int LIM = 60;
const double min_confidence = 0.8;

bool is_subset(vector<string> item, vector<string> big_item) {
	if (item.empty())
		return true;
	for (int i = 0, j = 0; i < item.size() && j < big_item.size(); ++j) {
		if (item[i] == big_item[j]) {
			++i;
			if (i == item.size())
				return true;
		}
	}
	return false;
}

double get_support(vector<string> item) {
	int cnt = 0;
	for (auto big_item : transactions) {
		if (is_subset(item, big_item))
			++cnt;
	}
	return (double)cnt / (double)transactions.size();
}

bool has_enough_support(vector<string> item) {
	return get_support(item) >= min_support;
}

bool can_join(vector<string> item_a, vector<string> item_b) {
	for (int i = 0; i < item_a.size() - 1; ++i) {
		if (item_a[i] != item_b[i])
			return false;
	}
	return true;
}

struct association_rule {
	vector<string> a, b;
	double confidence;
};

set<pair< pair<vector<string>, vector<string> >, double> > association_rules;

vector<string> join(vector<string> item_a, vector<string> item_b) {
	string last_a = item_a.back();
	item_a.pop_back();

	string last_b = item_b.back();
	item_b.pop_back();

	if (last_a > last_b)
		swap(last_a, last_b);

	item_a.push_back(last_a);
	item_a.push_back(last_b);

	return item_a;
}

vector<vector<string> > generate_nextL(vector<vector<string> > L) {
	vector<vector<string> > next_L;
	for (int i = 0; i < L.size(); ++i) {
		for (int j = i + 1; j < L.size(); ++j) {
			if (can_join(L[i], L[j])) {
				vector<string> next_item = join(L[i], L[j]);
				if (has_enough_support(next_item))
					next_L.push_back(next_item);
			}
		}
	}
	return next_L;
}


void generate_association_rule(vector<string> item, vector<string> a, vector<string> b, int idx) {
	if (idx == item.size()) {
		if (a.empty() || b.empty())
			return;
		double item_support = get_support(item);
		double a_support = get_support(a);

		if (item_support / a_support >= min_confidence) {
			association_rules.insert(MP(MP(a, b), item_support / a_support));
		}

		return;
	}

	a.PB(item[idx]);
	generate_association_rule(item, a, b, idx + 1);
	a.pop_back();
	b.PB(item[idx]);
	generate_association_rule(item, a, b, idx + 1);
}

void make_rules() {
	for (auto s : dictionary) {
		if (has_enough_support(vector<string>(1, s)))
			L.push_back(vector<string>(1, s));
	}

	int sz = 1;

	while (!L.empty()) {
		for (auto item : L) {
			frequent_set.push_back(item);
		}
		L = generate_nextL(L);
	}
	for (auto i : frequent_set) {
		vector<string> a, b;
		generate_association_rule(i, a, b, 0);
	}
}

void input() {
	ifstream fin("1404001_2018-10-28.csv");

	if (!fin) {
		cerr << "ERROR";
		exit(0);
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
				p_store.insert(t);
				tmp.push_back(t);
			}
		}
		transactions.push_back(tmp);
	}

	for (auto it : p_store) {
		dictionary.push_back(it);
	}
}

int main() {
	input();
	make_rules();

	cout << association_rules << endl;
}