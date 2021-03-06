/*
ID: erfan.a2
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <memory.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T b; ss >> b; return b; }
template<class T> void print(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a; }
template<class T> bool isPrime(T a) { if (a == 1) return false; T n = (T)sqrt(a); for (T i = 2; i <= n; i++) if (a % i == 0) return false; return true; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const double eps = 1e-9;
const double pi = 3.141592654;
#define vec vector
#define un unsigned
#define pb push_back
#define mp make_pair
#define IT iterator
#define X first
#define Y second
#define debug(x) cerr << #x << " = " << x << " #" << __LINE__ << '\n'
#define sqr(a) ((a) * (a))
#define sz(x) ((int)(x).size())
#define first(x) (*((x).begin()))
#define last(x) (*((x).end() - 1))
#define ms(x, a) memset(x, a, sizeof x)
#define test() cerr << "Test!" << " #" << __LINE__ << '\n'
#define For(i, a, b) for(typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for(typeof(a) i = (a); i >= (b); i--)
#define Fit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Fitd(i, v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i--)
#define all(n) (n).begin(), (n).end()
#define wln(x) cout << x << '\n'
#define w(x) cout << x
#define r(x, type); type x; cin >> x;
#define rs(x); string x; getline(cin, x);
#define rarr(array, i, a, n); for(int i = a; i <= n; i++) cin >> array[i];
#define warr(array, i, a, n); for(int i = a; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, a, n); for(int i = n; i >= a; i--) cout << array[i] << " ";
#define maxn 100010

//#define cin fin
//#define cout fout
ofstream fout("msquare.out");
ifstream fin("msquare.in");

struct square
{
	int row1[4];
	int row2[4];
	void operator = (square s)
	{
		For (i, 0, 3)
			row1[i] = s.row1[i];
		For (i, 0, 3)
			row2[i] = s.row2[i];
	}
	bool operator == (square s)
	{
		For (i, 0, 3)
			if (row1[i] != s.row1[i])
				return false;
		For (i, 0, 3)
			if (row2[i] != s.row2[i])
				return false;
		return true;
	}
} src, dest;

void a(int* x, int* y)
{
	For (i, 0, 3)
		swap(x[i], y[i]);
}

void b(int* x)
{
	int y = x[3];
	Ford (i, 3, 1)
		x[i] = x[i - 1];
	x[0] = y;
}

void c(int* x, int* y)
{
	int z = y[1];
	y[1] = y[2];
	y[2] = x[2];
	x[2] = x[1];
	x[1] = z;
}

bool comp(string s1, string s2)
{
	if (sz(s1) < sz(s2))
		return true;
	if (sz(s1) > sz(s2))
		return false;
	return s1 < s2;
}

/*pair<square, string> q[100000];

void bfs()
{
	int l = 1;
	q[0].X = src;
	q[0].Y = "";
	int j, k;
	For (i, 0, 1000000 - 1)
	{
		j = i % 100000;
		k = (l - 1) % 100000;
		k++;
		if (q[j].X == dest)
		{
			cout << sz(q[j].Y) << endl;
			cout << q[j].Y << endl;
			exit(0);
		}
		square t = q[j].X;
		a(t.row1, t.row2);
		q[k - 1] = mp(t, q[j].Y + "A");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
		t = q[j].X;
		b(t.row1);
		b(t.row2);
		q[k - 1] = mp(t, q[j].Y + "B");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
		t = q[j].X;
		c(t.row1, t.row2);
		q[k - 1] = mp(t, q[j].Y + "C");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
	}
}*/

pair<square, string> q;

void bfs()
{
	int l = 1;
	q[0].X = src;
	q[0].Y = "";
	int j, k;
	For (i, 0, 1000000 - 1)
	{
		j = i % 100000;
		k = (l - 1) % 100000;
		k++;
		if (q[j].X == dest)
		{
			cout << sz(q[j].Y) << endl;
			cout << q[j].Y << endl;
			exit(0);
		}
		square t = q[j].X;
		a(t.row1, t.row2);
		q[k - 1] = mp(t, q[j].Y + "A");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
		t = q[j].X;
		b(t.row1);
		b(t.row2);
		q[k - 1] = mp(t, q[j].Y + "B");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
		t = q[j].X;
		c(t.row1, t.row2);
		q[k - 1] = mp(t, q[j].Y + "C");
		if (q[k - 1].X == dest)
		{
			cout << sz(q[k - 1].Y) << endl;
			cout << q[k - 1].Y << endl;
			exit(0);
		}
		k++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	For (i, 0, 3)
	{
		src.row1[i] = i + 1;
		src.row2[3 - i] = i + 5;
	}
	For (i, 0, 3)
		cin >> dest.row1[i];
	For (i, 0, 3)
		cin >> dest.row2[3 - i];
	bfs();
	return 0;
}
