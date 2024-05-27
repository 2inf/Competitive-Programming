#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define debug(x) cerr << #x << " is " << x << endl
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    string b;
    cin >> n >> b;
    vector<int> vis(26, 0), r;
    for (auto c : b) {
        vis[c-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (vis[i]) r.push_back(i);
    }

    int m = r.size();
    unordered_map<char, char> mp;
    for (int i = 0; i < m; i++) {
        mp['a'+r[i]] = 'a' + r[m-i-1]; 
    }
    for (int i = 0; i < n; i++) {
        cout << mp[b[i]];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}