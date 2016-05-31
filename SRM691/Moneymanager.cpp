// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// One day Hero realized that he has zero experience with practical projects.
Thus, he decided to spend one whole year on projects, gaining some experience and making some money along the way.

Hero already chose which projects he is going to do.
All that remains is to choose the order in which he'll do them.

Each project can be described by two positive integers a[i] and b[i].
More precisely, when Hero works on project i, the following two things happen, in order:

First, his work on the project increases his experience by a[i].
Then, when the project is done, he earns money for the project. The amount earned is (b[i] * E), where E is his total amount of experience at the moment of finishing the project.


The number of projects Hero has planned is even.
In addition to the projects, Hero has one extra plan: after finishing exactly one half of the projects, he wants to attend a training camp.
The training camp will increase his experience by X.
He will not earn any money at the training camp.

At the beginning, Hero has no experience and no money.
You are given the vector <int>s a and b (both with the same number of elements; that number is even) and the int X.
Find and return the maximum total amount of money Hero can earn during the year.

DEFINITION
Class:Moneymanager
Method:getbest
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int getbest(vector <int> a, vector <int> b, int X)


CONSTRAINTS
-Number of elements in a will be between 2 and 50, inclusive.
-Number of elements in a will be even.
-a and b will contain the same number of elements.
-Each element in a will be between 1 and 100,000, inclusive.
-Each element in b will be between 1 and 10, inclusive.
-X will be between 0 and 100,000, inclusive.


EXAMPLES

0)
{1,1}
{2,1}
0

Returns: 5

An optimal solution:

Hero works on project #1 (zero-based index). He first gains 1 experience and then he makes 1*1 = 1 money.
Hero goes to the training camp and gains X=0 experience.
Hero works on project #0. He first gains 1 experience and then he makes 2*2 = 4 money.

The total amount of money earned during this solution is 1 + 4 = 5.

1)
{1,1}
{1,5}
10

Returns: 61

An optimal solution:

Hero works on project #0. He first gains 1 experience and then he makes 1*1 = 1 money.
Hero goes to the training camp and gains 10 experience.
Hero works on project #1. He first gains 1 experience and then he makes 5*12 = 60 money.

The total amount of money earned during this solution is 1 + 60 = 61.

2)
{4,4,6,6}
{2,2,3,3}
100

Returns: 726

One optimal solution: project #0, project #1, training camp, project #3, project #2.

3)
{30,13,28,59,26,62,48,75,6,69,94,51}
{4,6,4,5,4,3,1,5,6,5,2,2}
62

Returns: 22096



*/
// END CUT HERE
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

bool cmp(pair<int,int> aa, pair<int,int> bb)
{
	return aa.first* bb.second > bb.first * aa.second;
}
int dp[55][30][300];
class Moneymanager {
	public:
	int getbest(vector <int> a, vector <int> b, int X) {
		int n = a.size();
		vector<pair<int,int> > c;
		FOR(i,0,n)
			c.PB(MP(a[i], b[i]));
		sort(ALL(c), cmp);
		if(X == 0)
		{
			LL res = 0;
			LL accu = 0;
			FOR(i,0,n)
			{
				accu += c[i].first;
				res += accu * c[i].second;
			}
			return res;
		}
		reverse(ALL(c));
		int res = 0;
		// index, # of items in second half, # of b[i] sums in the second half
		FORE(tot, 0, n * 5)
		{
			NEG(dp);
			dp[0][0][0] = 0;
			int sum = 0;
			FOR(i,0,n)
			{
				sum += c[i].second;
				FOR(j,0,n / 2 + 1)
				{
					FORE(k,0,n * 5)
					{
						if(dp[i][j][k] < 0)
							continue;
						int aa = c[i].first;
						int bb = c[i].second;
						dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (sum - k + tot) * aa);
						dp[i + 1][j + 1][k + bb] = max(dp[i + 1][j + 1][k + bb], dp[i][j][k] + aa * (k + bb));
					}
				}
			}
			if(dp[n][n / 2][tot] >= 0)
			{
				res = max(res, dp[n][n / 2][tot] + tot * X);
			}
		}
		return res;
	}

};
