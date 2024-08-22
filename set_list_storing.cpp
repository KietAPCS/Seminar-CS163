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

vector<int> lst[N];
int parent[N];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
    }
}

int main() {
    cout << "Enter total elements: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    cout << "Enter number of union operations: ";
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Union operation " << i + 1 << ": ";
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }

    cout << "Enter number of find operations: ";
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        cout << "Find operation " << i + 1 << ": ";
        int u;
        cin >> u;
        int parent = find_set(u);
        cout << "Element " << u << " belongs to set with representative: " << parent << '\n';
    }

    for (int i = 0; i < n; i++) {
        if (lst[i].size() != 0) {
            cout << "List " << i << ": ";
            for (auto x : lst[i]) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
