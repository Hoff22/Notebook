#define fi first
#define se second

vector<int> build_suffix_arr(string s, char small = '$'){
	s += small;
	int n = s.size();

	vector<int> p(n), c(n);
	vector<pair<pair<int,int>,int>> a(n);

	auto step = [&](){
		sort(a.begin(), a.end());
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
		step();
	}

	int k = 0;
	while((1ll<<k) < n){
		for(int i = 0; i < n; i++){
			a[i] = {{c[i], c[(i + (1<<k)) % n]}, i};
		}
		step();
		k++;
	}

	return p;
}