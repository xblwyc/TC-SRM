#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ostream>
#include <queue>
#include <cmath>
#include <climits>
#include <utility>
#include <fstream>
#include <memory>
#include <sstream>
#include <set>
#include <iterator>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
#define FOR(a, b, n) for(int (a) = (b); (a) < (n); ++(a))
#define FORE(a, b, n) for(int (a) = (b); (a) <= (n); ++(a))
#define ITE(a, v) for(auto (a) = v.begin(); (a) != v.end(); ++(a))
#define LL long long
#define ALL(v) v.begin(),v.end()
#define ZERO(v) memset(v, 0, sizeof v)
#define NEG(v)  memset(v, -1, sizeof v)
#define F first
#define S second
#define LD double
#define pw(x) (1LL << (x))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define PI 3.141592653589793
#define PII pair<LL, LL>
#define INF 0x3f3f3f3f
#define FUL(x) memset(x, 0x3f, sizeof(x));
#define debug(args...) {cerr << #args << " = "; errDebug(args); cerr << endl;}
void errDebug() {}
template<typename T, typename... Args>
void errDebug(T a, Args... args) {
    cerr << a << ' ';
    errDebug(args...);
}


class Sunnygraphs {
public:
	long long count(vector <int>);
};
long long Sunnygraphs::count(vector <int> a) {
	set<int> aa;
	set<int> bb;
	int n = a.size();
	int p = 0;
	while(aa.count(p) == 0)
	{
		aa.insert(p);
		p = a[p];
	}
	p = 1;
	while(bb.count(p) == 0)
	{
		bb.insert(p);
		p = a[p];
	}
	int c = 0;
	FOR(i,0,n)
	{
		if(aa.count(i) && bb.count(i))
			c++;
	}
	if(c == 0)
	{
		int rest = n - aa.size() - bb.size();
		LL res = (pw(aa.size()) - 1) * (pw(bb.size()) - 1);
		res *= pw(rest);
		return res;
	}
	int aaa = aa.size() - c;
	int bbb = bb.size() - c;
	int rest = (n - aaa - bbb - c);
	LL res = pw(n) - ((pw(aaa) - 1) + (pw(bbb) - 1)) * pw(rest);
	return res;
}
