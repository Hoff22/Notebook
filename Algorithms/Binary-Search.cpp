
// O(1)
bool check(int x, int k){
	return x < k;
}

// O(log_2(N))
int _lower_bound(vector<int> a, int k){
	int l = 0;
	int r = (int)a.size()-1;
	int m;

	int ans = a[r];

	while(l < r){
		m = l + (r-l) / 2;

		if(check(a[m], k)){
			l = m+1;
		}
		else if(!check(a[m], k)){
			r = m;
		}
		else{
			r = m;
			ans = m;
		}
	}

	return ans;
}

// O(log_2(N))
int _upper_bound(vector<int> a, int k){
	int l = 0;
	int r = (int)a.size()-1;
	int m;

	int ans = a[r];

	while(l < r){
		m = l + (r-l) / 2;
 
		if(check(a[m], k)){
			l = m+1;
		}
		else if(!check(a[m], k)){
			r = m;
		}
		else{
			l = m+1;
			ans = m;
		}
	}

	return ans;
}