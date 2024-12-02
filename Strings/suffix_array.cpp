#define fi first
#define se second

// O(N + N*log(N))
vector<int> build_suffix_arr(string s, char small = '$'){
	s += small;
	int n = s.size();

	vector<int> p(n), c(n);
	vector<pair<pair<int,int>,int>> a(n);

	auto step = [&](){
		for(int i = 0; i < n; i++) p[i] = a[i].se;
		c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			if(a[i].fi == a[i-1].fi) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]] + 1;
		}
	};

	// 0 pass
	{
		for(int i = 0; i < n; i++) a[i] = {{s[i],s[i]},i};
		sort(a.begin(), a.end());
		step();
	}

	int k = 0;
	while((1ll<<k) < n){
		for(int i = 0; i < n; i++){
			a[i] = {{c[i], c[(i + (1<<k)) % n]}, i};
		}

		//radix #1
		vector<vector<pair<pair<int,int>,int>>> rad(n,vector<pair<pair<int,int>,int>>());

		for(auto x : a){
			rad[x.fi.se].push_back(x);
		}
		a.clear();
		for(auto v : rad){
			for(auto x : v) a.push_back(x);
		}

		//radix #2
		rad.assign(n,vector<pair<pair<int,int>,int>>());
		for(auto x : a){
			rad[x.fi.fi].push_back(x);
		}
		a.clear();
		for(auto v : rad){
			for(auto x : v) a.push_back(x);
		}

	// -- 
		
		step();
		k++;
	}

	return p;
}