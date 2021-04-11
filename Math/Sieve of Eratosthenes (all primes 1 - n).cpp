vector<int> RangePrimes(int n){
	vector<int> v(n+1, 0);
	vector<int> primes;
	int i = 2;
	while(i <= n){
		if(v[i] == 0) primes.push_back(i);
		if(v[i] == 0 and 1ll*i*i <= n){
			int j = i*i;
			while(j <= n){
				v[j] = 1;
				j += i;
			}
		}
		i++;
	}
	return primes;
}