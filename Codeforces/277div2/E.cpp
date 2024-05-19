#include <bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << " is " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    auto lis = [&](vector<int> a) {
        vector<int> dp(a.size(), INF), ret;
        for (auto x : a) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            *it = x;
            ret.push_back(it - dp.begin() + 1);
        }
        return ret;
    };

    auto l = lis(a);
    reverse(a.begin(), a.end());
    for (auto &e : a) e = -e;
    auto r = lis(a);

    int ma = *max_element(l.begin(), l.end());
    vector<int> len(ma + 1);
    for (int i = 0; i < n; i++) {
        if (l[i] + r[n-i-1] - 1 == ma) len[l[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (l[i] + r[n-i-1] - 1 != ma) cout << "1";
        else if (len[l[i]] != 1) cout << "2";
        else cout << "3";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}