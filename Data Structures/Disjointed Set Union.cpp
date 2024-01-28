// each set is a tree, the root of the tree is te LEADER of
// the set
#define N 10000 // number of elements

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
