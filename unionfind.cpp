#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second

vector<vector<int>> sz(n, vector<int>(m, 1));
vector<vector<pii>> parent(n, vector<pii>(m));

pii root(int x, int y) {
    if(parent[x][y].f == x && parent[x][y].s == y) return parent[x][y];
    return parent[x][y] = root(parent[x][y].f, parent[x][y].s);
}

void join(int a, int b, int c, int d) {
    pii x = root(a, b), y = root(c, d);
    if(x == y) return;
    if(sz[x.f][x.s] > sz[y.f][y.s]) swap(x, y);
    parent[x.f][x.s] = y;
    sz[y.f][y.s] += sz[x.f][x.s];
}

for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) parent[i][j] = mp(i, j);
}
