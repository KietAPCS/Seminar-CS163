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

int parent[N];

void make_set(int u) {
    parent[u] = u;
}

int find(int u) {
    if (parent[u] == u) {
        return u;
    }
    return find(parent[u]);
}

void union_set(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[v] = u;
    }
}

int main() {

    cout << "Enter n: ";
    int n; cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        cout << "Enter a[" << i << "]: ";
        int x; cin >> x;
        make_set(x);
        a.push_back(x);
    }

    union_set(a[1], a[2]);

    cout << "Parent of: \n";
    for (int i = 0; i < n; i++) {
        cout << "+ ";
        cout << a[i] << " is: " << parent[a[i]] << "\n";
    }

    return 0;
}