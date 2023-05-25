#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> vll;
typedef tuple <ll, ll, ll, ll, ll> tl;
typedef tuple<int, int, int> ti;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const int N = 100003;
const ll inf = 1000000007;
int n;
ll a[N], b[N];
ll dp[N][3];

ll solve(ll x, ll p)
{
	ll& ret = dp[x][p];
	if (ret != -1) return ret;
	if (x == n) return ret = 1;

	ret = solve(x + 1, 0) * a[x];
	ret %= inf;
	if (x - 1 >= 0 && b[x - 1] - p > 0)
	{
		ret += solve(x + 1, 0) * (b[x - 1] - p);
		ret %= inf;
	}
	ret += solve(x + 1, 1) * b[x];
	ret %= inf;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) cin >> b[i];

	cout << solve(0, 0);
}