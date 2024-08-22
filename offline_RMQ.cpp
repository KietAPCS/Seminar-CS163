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

struct Query {
    int L, R, idx;
};

int answer[N];
int parent[N];
int a[N];
vector<Query> container[N];

void make_set(int u) {
    parent[u] = u;
}

int find_set(int u) {
    return parent[u] == u ? u : parent[u] = find_set(parent[u]);
}

int main() {

    cout << "Enter total numbers: ";
    int n; cin >> n;

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        make_set(i);
    }

    cout << "Enter total queries: ";

    int m; cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Query " << i << ": ";
        int l, r;
        cin >> l >> r;
        Query tmp = {l, r, i};
        container[r].push_back(tmp);
    }

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) {
            parent[st.top()] = i; 
            st.pop();
        }
        st.push(i);
        for (Query q : container[i]) {
            answer[q.idx] = a[find_set(q.L)];
        }
    }

    cout << "Answer: \n";

    for (int i = 0; i < n; i++) {
        if (container[i].size() != 0) {
            for (Query q : container[i]) {
                cout << "Query " << q.idx << " from " << q.L << " to " << q.R << " is: " << answer[q.idx] << "\n";
            }
        }
    }

    return 0;
}