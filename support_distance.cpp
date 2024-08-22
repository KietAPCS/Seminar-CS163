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

int Rank[N];
pair<int,int> parent[N];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    Rank[v] = 0;
}

pair<int,int> find_set(int v) {
    if (v != parent[v].first) {
        int cur_len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += cur_len;
    }
    return parent[v];
}

void union_set(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;

    if (a != b) {
        if (Rank[a] < Rank[b]) {
            swap(a, b);
        }
        parent[b] = make_pair(a, 1);
        if (Rank[a] == Rank[b]) {
            Rank[a]++;
        }
    }
}

int main() {

    int n = 5;
    vector<int> a = {11, 22, 56, 33, 67};

    for (int i = 0; i < n; i++) {
        make_set(a[i]);
    }

    union_set(a[0], a[1]);
    union_set(a[n-2], a[n-1]);
    union_set(a[2], a[3]);
    
    cout << "Before union all sets: \n";

    for (int i = 0; i < n; i++) {
        cout << "Node: " << a[i] << " " << "Parent: " << parent[a[i]].first << " " << "Distance: " << parent[a[i]].second << "\n";
    }

    cout << "After union all sets: \n";

    union_set(a[1], a[2]);
    

    for (int i = 0; i < n; i++) {
        cout << "Node: " << a[i] << " " << "Parent: " << parent[a[i]].first << " " << "Distance: " << parent[a[i]].second << "\n";
    }

    return 0;
}