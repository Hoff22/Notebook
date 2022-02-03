constexpr int N = 200000; // MAX VERTICES

/*
	Computes the lowest common ancestor of two vertices in a tree
	in O(logV) after a pre-processing of O(V * logV).

	Can be used to compute distance of two vertices in O(logV):

		dist(u,v) = height(u) + height(v) - 2 * height(lca(u,v))
*/

int n; 							// (input) number of vertices
vector<int> g[N+1]; 			// (input) tree 
int tin[N+1]; 					// dfs time of entry for each vertex
int tout[N+1]; 					// dfs time of exit for each vertex
int up[N+1][ceil(log2(N)) + 1]; // up[u][x] is the 2^x-th ancestor of node u


int timer = 0;
int dfs1(int u, int parent){
	up[u][0] = parent;

	tin[u] = ++timer;
	
	for(int v : g[u]){
		dfs1(v, u);
	}

	tout[u] = ++timer;
}

/* O(N * logN) */ // obligatory pre-processing
void build(int root){
	timer = 0;
	// Clearing

	dfs(root, root); // precompute up[u][0] and tin[u] for each vertex
	// up[0][i] = 0 for any i

	for(int i = 1; i <= ceil(log2(N)); i++){
		for(int u = 1; u <= n; u++){
			up[u][i] = up[up[u][i-1]][i-1];
		}
	}
}

bool is_ancestor(int a, int u){
	return (tin[a] < tin[u] and tin[u] < tout[a]);
}

/* O(logN) */
int lca(int u, int v){
	if(is_ancestor(u, v)){
		return u;
	}
	if(is_ancestor(v, u)){
		return v;
	}

	for(int k = ceil(log2(N)); k >= 0; k--){
		if(!is_ancestor(up[u][k], v)){
			u = up[u][k];
		}
	}

	return up[u][0];
}