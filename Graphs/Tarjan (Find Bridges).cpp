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
int ap[N+1];

int timer = 0;

// O(N+M);
void tarjan(int u, int p){

	seen[u] = true;

	tin[u] = low[u] = timer++;

	int child = 0;

	for(int v : g[u]){
		if(v == p) continue;
		if(!seen[v]){
			//parent[v] = u;
			child++;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);

			// u is root with more than 1 child or there's no path from subtree of node v to u using back-edges.
			// so removing u is going to disconect v's subtree
			if((!p and child >= 2) or (p and low[v] >= tin[u])){
				ap[u] = 1;
			}

			// u->v is a bridge:
			if(low[v] > tin[u]){
				bridges.push_back({u,v});
			}
		}// v is a back-edge:
		else{
			low[u] = min(tin[v], low[u]);
		}
	}
}