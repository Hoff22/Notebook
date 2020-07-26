#define N 100000

vector<int> g[N + 1];
bool seen[N + 1];
int n;

// O(V + E).
void dfs(int u) {
	seen[u] = true;

	for (int = 0; i < g[u].size(); i++) {
		int v = g[u][i];

		if (!seen[v]) {
			dfs(v);
		}
	}
}

int main() {
	int m, u, v;

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}

	dfs(1);

	if (seen[n]) {
		printf("1 chega em n\n");
	}
	else {
		printf("1 nao chega em n\n");
	}

	return 0;
}
