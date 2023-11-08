#define N 200000

// graph:
vector<int> g[N+1];
// Seen:
bool seen[N+1];
// Discovery Time:
int tin[N+1];
// Lowest tin achivable by node v:
int low[N+1];
// Bridges:
vector<pair<int, int>> bridges;

int timer = 0;

// O(N+M);
void tarjan(int u, int p){

	seen[u] = true;

	tin[u] = low[u] = timer++;

	for(int v : g[u]){
		if(v == p) continue;
		if(!seen[v]){
			//parent[v] = u;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			// u->v is a bridge and u is not a leaf:
			if(low[v] > tin[u] and g[u].size() > 1){
				bridges.push_back({u,v});
			}
		}// v is a back-edge:
		else{
			low[u] = min(tin[v], low[u]);
		}
	}
}