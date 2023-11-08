#define LOG_MAX 30

struct bit_trie{
	int sz, child[2];

	bit_trie(){
		this->sz = 0;
		this->child[0] = this->child[1] = -1;
	}
};

vector<bit_trie> bt = {bit_trie()};

// O(log(N));
void insert(int n, vector<bit_trie>& t){

	int cur = 0;

	for(int i = 30; i >= 0; i--){
		
		t[cur].sz++;

		if(t[cur].child[0] == -1){
			t[cur].child[0] = t.size();
			t.push_back(bit_trie());
			t[cur].child[1] = t.size();
			t.push_back(bit_trie());
		}

		cur = t[cur].child[(n>>i) & 1];
	}

	t[cur].sz++;
}

// O(log(N));
// number of y such that n^y == x; xor_count(0, x) == count(x)
int xor_count(int n, int x, vector<bit_trie>& t){
	int cur = 0;
	for(int i = LOG_MAX; i >= 0; i--){
		if(t[cur].sz == 0) break;
		cur = t[cur].child[((n>>i) ^ (x>>i)) & 1];
	}

	return t[cur].sz;
}

// O(log(N));
// returns the max xor possible with n
int xor_max(int n, vector<bit_trie>& t){
	int cur = 0;
	long long ans = 0;
	
	if(t[cur].sz == 0) return -1;

	for(int i = LOG_MAX; i >= 0; i--){
		if(t[t[cur].child[!((n>>i) & 1)]].sz > 0){
			ans += (1<<i);
			cur = t[cur].child[!((n>>i) & 1)];
		}
		else{
			cur = t[cur].child[((n>>i) & 1)];
		}
	}

	return ans;
}

// O(log(N));
int xor_min(int n, vector<bit_trie>& t){
	int cur = 0;
	long long ans = 0;
	
	if(t[cur].sz == 0) return -1;

	for(int i = LOG_MAX; i >= 0; i--){
		if(t[t[cur].child[((n>>i) & 1)]].sz > 0){
			cur = t[cur].child[((n>>i) & 1)];
		}
		else{
			ans += (1<<i);
			cur = t[cur].child[!((n>>i) & 1)];
		}
	}

	return ans;
}