int constexpr N = 200000;

vector<int> g[N+1]; // (input) tree edges g[u] is a list of verts that share an edge with u
int DP[N+1][2];

// O(N)
int matching(int u, int used, int p){
	
	if(DP[u][used] != -1) return DP[u][used];

	int r = 0;
	
	if(used){
		for(int v : g[u]){
			if(v == p) continue;

			r += dp(v, 0, u);
		}
	}
	else{
		int sum = 0;
		for(int v : g[u]){
			if(v == p) continue;

			sum += dp(v, 0, u);
		}

		r = sum;

		for(int v : g[u]){
			if(v == p) continue;

			r = max(r, sum - dp(v, 0, u) + dp(v, 1, u) + 1);
		}
	}

	return DP[u][used] = r;
}