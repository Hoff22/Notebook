typedef long long ll;

vector<pair<int, ll>> g[N + 1]; // (Input)
ll dist[N + 1][N + 1];

/* O(E + V^3). */
void floyd(int n) {
	// Initializing.
	memset(dist, 0x3f, sizeof(dist));

	for(int i = 1; i <= n; i++){
		dist[i][i] = 0;
		for(auto [v,w] : g[i]){
			dist[i][v] = min(dist[i][v], w);
		}
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}