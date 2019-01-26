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

class dataset {
public:

	vector<string> attr_name;
	vector<vector<string> > data;

	vector<vector<string> > attr_value_list;

	bool is_attribute_value_extracted = false;

	void extract_attribute_value() {
		if (is_attribute_value_extracted)
			return;
		is_attribute_value_extracted = true;
		attr_value_list.resize(attr_name.size());
		for (int i = 0; i < attr_name.size(); ++i) {
			set<string> value;
			for (int j = 0; j < data.size(); ++j)
				value.insert(data[j][i]);
			for (auto it : value)
				attr_value_list[i].PB(it);
		}
	}
};

class node {
public:

	int max_entropy_gain_idx;

	string attr_value;

	int tree_idx;
	bool is_leaf;

	string label;

	vector<int> children;

	node() {
		is_leaf = false;
	}
};

class decision_tree {
public:

	dataset initial_dataset;
	vector<node> tree;

	decision_tree(dataset cur_dataset) {
		initial_dataset = cur_dataset;
		cur_dataset.extract_attribute_value();

		node root;
		root.tree_idx = 0;
		tree.PB(root);

		gen(cur_dataset, 0);
	}

	void gen(dataset cur_dataset, int node_idx) {
		if (all_same_label(cur_dataset)) {
			tree[node_idx].is_leaf = true;
			tree[node_idx].label = cur_dataset.data.back().back();
			return;
		}

		if (cur_dataset.data.empty()) {
			tree[node_idx].is_leaf = true;
			tree[node_idx].label = "?";
			return;
		}

		if (cur_dataset.data[0].size() == 1) {
			tree[node_idx].is_leaf = true;
			tree[node_idx].label = get_max_label(cur_dataset);
			return;
		}

		cur_dataset.extract_attribute_value();


		tree[node_idx].max_entropy_gain_idx = get_best_idx(cur_dataset);
		tree[node_idx].children.resize(cur_dataset.attr_value_list[tree[node_idx].max_entropy_gain_idx].size());

		for (int i = 0; i < cur_dataset.attr_value_list[tree[node_idx].max_entropy_gain_idx].size(); ++i) { dbg(i, cur_dataset.attr_value_list[tree[node_idx].max_entropy_gain_idx].size());
			string req_attribute = cur_dataset.attr_value_list[tree[node_idx].max_entropy_gain_idx][i];
			dataset tmp_dataset;

			for (int j = 0; j < cur_dataset.data.size(); ++j) {
				if (cur_dataset.data[j][tree[node_idx].max_entropy_gain_idx] == req_attribute)
					tmp_dataset.data.PB(cur_dataset.data[j]);
			}

			tmp_dataset.attr_name = cur_dataset.attr_name;

			tmp_dataset.attr_name.erase(tmp_dataset.attr_name.begin() + tree[node_idx].max_entropy_gain_idx);

			for (auto &tds : tmp_dataset.data)
				tds.erase(tds.begin() + tree[node_idx].max_entropy_gain_idx);

			tree[node_idx].children[i] = tree.size();
			node new_node;
			new_node.tree_idx = tree[node_idx].children[i];
			new_node.attr_value = req_attribute;
			tree.PB(new_node);
			gen(tmp_dataset, tree[node_idx].children[i]);
		}
	}

	int dfs(vector<string> &query, int node_idx) {
		if (tree[node_idx].is_leaf)
			return node_idx;

		for (int i = 0; i < tree[node_idx].children.size(); ++i) {
			int nxt_idx = tree[node_idx].children[i];
			if (tree[nxt_idx].attr_value == query[tree[node_idx].max_entropy_gain_idx]) {
				query.erase(query.begin() + tree[node_idx].max_entropy_gain_idx);
				return dfs(query, nxt_idx);
			}
		}
	}

	string get_max_label(dataset cur_dataset) {
		map<string, int> cnt;
		int max_cnt = 0;
		string max_label;
		for (int i = 0; i < cur_dataset.data.size(); ++i) {
			cnt[cur_dataset.data[i][0]]++;
			if (max_cnt < cnt[cur_dataset.data[i][0]]) {
				max_cnt = cnt[cur_dataset.data[i][0]];
				max_label = cur_dataset.data[i][0];
			}
		}
		return max_label;
	}

	bool all_same_label(dataset cur_dataset) {
		for (int i = 1; i < cur_dataset.data.size(); ++i)
			if (cur_dataset.data[0].back() != cur_dataset.data[i].back())
				return false;
		return true;
	}

	int get_best_idx(dataset cur_dataset) {
		double cur_entropy = calc_entropy(cur_dataset);

		int max_entropy_gain_idx = -1;

		double max_entropy_gain = -1;

		cur_dataset.extract_attribute_value();

		for (int i = 0; i < cur_dataset.attr_name.size() - 1; ++i) {
			double entropy_sum = 0;
			for (int j = 0; j < cur_dataset.attr_value_list[i].size(); ++j) {
				dataset tmp_dataset;
				for (int k = 0; k < cur_dataset.data.size(); ++k) {
					//may be buggy
					if (cur_dataset.data[k][i] == cur_dataset.attr_value_list[i][j])
						tmp_dataset.data.PB(cur_dataset.data[k]);
				}
				entropy_sum += (double)(tmp_dataset.data.size()) / (double)(cur_dataset.data.size()) * calc_entropy(tmp_dataset);
			}

			if (cur_entropy - entropy_sum > max_entropy_gain) {
				max_entropy_gain = cur_entropy - entropy_sum;
				max_entropy_gain_idx = i;
			}
		}

		return max_entropy_gain_idx;
	}

	double calc_entropy(dataset cur_dataset) {
		map<string, int> cnt;

		double ret = 0;

		for (int i = 0; i < cur_dataset.data.size(); ++i) {
			cnt[cur_dataset.data[i].back()]++;
		}

		for (auto it : cnt) {
			double tmp = (double)it.S / (double)(cur_dataset.data.size());
			ret -= log2(tmp) * tmp;
		}

		return ret;
	}
};

dataset input() {

	dataset ds;

	string input_file;
	//cin >> input_file;

	ifstream fin("1404001_2018-10-28.csv");

	if (!fin) {
		cerr << "ERROR IN FILE" << endl;
	}

	string s;
	getline(fin, s);

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '"') {
			string t;
			++i;
			while (s[i] != '"') {
				t.push_back(s[i]);
				++i;
			}
			ds.attr_name.push_back(t);
		}
	}

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
		ds.data.push_back(tmp);
	}

	return ds;
}

int main() {
	dataset cur_dataset = input();
	decision_tree dt(cur_dataset);
	int cnt = 0;;

	for (int i = 0; i < cur_dataset.data.size(); ++i) {
		int yo = dt.dfs(cur_dataset.data[i], 0);
		cout << dt.tree[yo].label << endl;
		if (dt.tree[yo].label == cur_dataset.data[i].back()) 
			++cnt;
	}

	cout << (double)cnt / (double)cur_dataset.data.size() * 100.0 << endl;
}