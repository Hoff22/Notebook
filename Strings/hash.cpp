#define MOD 10e9+7;

/*
	input: O(N)
	hash_str ht(string str)	// create hash object of string str

	usage: O(1)
	ht.sub_hash(l, r) 		// hash value for substr in range [l,r] of str;
*/

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int r = uniform_int_distribution<int>(0, MOD-1)(rng);
struct hash_str{
	vector<long long> h; // hash of prefixes
	vector<long long> p; // powers of r (random value) for range querys of hash

	/* O(N) */
	hash_str(string s) : h(s.size()), p(s.size()){
		int n = s.size();
		h[0] = s[0];
		for(int i = 1; i < n; i++){
			h[i] = (h[i-1] * r + s[i]) % MOD;
		}

		p[0] = 1;
		for(int i = 1; i < n; i++){
			p[i] = (p[i-1] * r) % MOD;
		}
	}

	/* O(1) */
	long long sub_hash(int l, int r){
		if(l == 0){
			return h[r];
		}
		long long ans = (h[r] - h[l-1] * p[r-l+1]) % MOD;
		ans += MOD
		ans %= MOD;

		return ans;
	}
};