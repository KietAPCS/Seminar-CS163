int par[N][LOG + 2];
vector <int> a[N];
int pos[N], f[N];
struct DSU {
    vector <int> rank;
    vector <int> to;
    void built(int n){
        rank.assign(n + 10,0);
        to.assign(n + 10,0);
        for (int i = 1 ; i <= n; i++){
            to[i]= i;
            a[i].clear();
        }
    }

    int trace(int u) {
        if (u != to[u]) return to[u] = trace(to[u]);
        return u;
    }

    void join(int u,int v){
        u = trace(u);
        a[v].push_back(u);
       // cout << v << " " << u << "\n";
        to[u] = v;
    }
} dsu;

struct node
{
    int x, y , val;
    node() {}
    node(int x,int y,int val): x(x), y(y), val(val){}

    bool operator < (const node k) const {
        return val > k.val;
    }
};

node b[N];
int n;
int q;
int high[N];

void dfs(int u) {
    if (!a[u].size()) f[u] = 1;
    else f[u] = 0;


    for (int v : a[u]){
        par[v][0] = u;
        dfs(v);
        f[u] += f[v];
    }
  // cout << u << " " << f[u] << "\n";
}

void solve(){
    cin >> n >> q;
    for (int i = 1 ; i < n ; i++) {
        int x , y , z;
        cin >> x >> y >> z;
        b[i] = node(x,y,z);
    }

    sort(b + 1,b + n);
    dsu.built(2*n);
    for (int i = 1 ; i < n ; i++) {
        dsu.join(b[i].x,n + i);
        dsu.join(b[i].y,n + i);
      //  cout << b[i].x << " " << b[i].y << " " << b[i].val << "\n";
    }

    par[2*n - 1][0] = 0;
    high[2*n - 1] = 0;
    high[0] = -1;
    b[0].val = -INF;
    dfs(2*n - 1);

    for (int j = 1 ; j < LOG ; j++)
    for (int i = 1 ; i < 2*n ; i++)
        par[i][j] = par[par[i][j - 1]][j - 1]; 

    while (q--){
        int u , c;
        cin >> u >> c;
        int g = u;
        for (int i = LOG ; i >= 0 ; i--)
            if (b[par[g][i] - n].val > c){
                g = par[g][i];
            }

        cout << f[2*n - 1] - f[g] << "\n";
    }
