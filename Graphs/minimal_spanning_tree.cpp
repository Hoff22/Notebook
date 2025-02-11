#define N 200000

namespace mst{
	int parent[N+1];
	int height[N+1];

	// make_set(a) creates a new set/tree with only the node a
	void make_set(int a){
		parent[a] = a;
		height[a] = 0;
	}

	// find(a) returns the answer to which set the element a belongs to
	int find_set(int a){
		if(parent[a] == a){
			return a;
		}
		return parent[a] = find_set(parent[a]);
	}

	// union(a, b) merges two sets into one
	void union_set(int a, int b){
		a = find_set(a);
		b = find_set(b);
		
		if(a != b){
			if(height[b] > height[a]) swap(a, b); // bigger's always a;
			parent[b] = a;
			if(height[a] == height[b]) height[a] += 1;
		}
	}

	// O(E * log(N)) - expects graph 1-indexed
	vector<vector<pair<int,int>>> mst(vector<vector<pair<int,int>>>& g){
		int n = g.size()-1;
		
		vector<vector<pair<int,int>>> res(n+1,vector<pair<int,int>>());

		for(int i = 1; i <= n; i++){
			make_set(i);
		}

		vector<tuple<int,int,int>> edges;
		for(int u = 1; u <= n; u++){
			// cout << "> " << u << endl;
			for(auto [v, w] : g[u]){
				edges.push_back({w,u,v});
			}
		}

		sort(edges.begin(), edges.end());

		for(auto [w,u,v] : edges){
			
			// cout << u << " " << v << " " << w << endl;

			if(find_set(v) == find_set(u)) continue;
			// cout << "  get" << endl;

			union_set(u,v);
			res[u].push_back({v,w});
			res[v].push_back({u,w});
			val += w;
		}

		return res;
	}
}