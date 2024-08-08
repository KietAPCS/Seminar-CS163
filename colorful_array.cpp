#include <bits/stdc++.h>
#define vll vector<ll>
#define vpii vector<pii>
#define vs vector<string>
#define el cout << '\n'
#define rt return;
#define mask(x) (1ll << (x))
#define bit(n,x) ((n >> x) & 1)
#define multiTest 0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 2e5;
const int mod = 1e9 + 7;

int parent[N+5];

void make_set(int u) {
    parent[u] = u;
}

int find_set(int u) {
    return parent[u] == u ? u : parent[u] = find_set(parent[u]);
}

struct Query {
    int L, R, C;
};

int a[N+5];
vector<Query> query;

void solve() {
   int n, q;
   cin >> n >> q;

   query.resize(q+1);

   for (int i = 1; i <= q; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        query[i] = {l, r, c};
   }

   for (int i = 1; i <= n + 1; i++) {
        make_set(i);
   }

   for (int i = q; i >= 1; i--) {
        int l = query[i].L;
        int r = query[i].R;
        int c = query[i].C;

        //cout << l << " " << r << " " << c << "\n";

        for (int v = find_set(l); v <= r; v = find_set(v)) {
            a[v] = c;
            parent[v] = v + 1;
        }
   }

   for (int i = 1; i <= n; i++) cout << a[i] << "\n";
}


int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#if multiTest
    ll t; cin >> t;
    while (t--) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
