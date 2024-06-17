#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> vll;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map<string, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        mp[s]++;
    }

    int mx = 0;
    string ans = "";

    for (auto to : mp)
    {
        if (mx < to.second)
        {
            mx = to.second;
            ans = to.first;
        }
    }

    cout << ans;
}