#define N 100000
#define LOG 20

// parent[v] == node u that is a parent to v;
int parent[N];
// ancestor[v][j] == node u that is the 2^j-th ancestor to v;
int ancestor[N][LOG];
// n == number of nodes;
int n;

void build(){
	// initializes dp of all 0-th ancestors wich are the parents itself
	for(int v = 0; v < n; v++){
		ancestor[v][0] = parent[v];
	}
	// fills all the 2^j-th ancestors using previous values
	// parent[v] < v must be true
	// parent[0] must be 0
	for(int v = 0; v < n; v++){
		for(int j = 1; j < LOG; j++){
			ancestor[v][j] = ancestor[ ancestor[v][j-1] ][j-1];
		}
	}
}
// given v and k returns the k-th ancestor to v
int query(int v, int k){
	int ans = v;
	int a = 0;
	while(k){
		if(k & 1){
			ans = ancestor[ans][a];
		}
		a++;
		k >>= 1;
	}
	return ans;
}




