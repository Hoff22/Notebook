int constexpr N = 200000;

vector<int> g[N+1]; // (input)
int far[N+1];		// farthest node from u

// O(N)
int dfs(int u, int p){
	far[u] = u;
	int dist = 0;
	for(int v : g[u]){
		if(v == p) continue;
		int vdist = dfs(v,u);
		if(dist < vdist+1){
			dist = vdist+1;
			far[u] = far[v];
		}
	}

	if(p == -1) return far[u];
	return dist;
}

// O(N)
int diameter(int root = 1){
	return dfs(dfs(root, -1), 0);
}