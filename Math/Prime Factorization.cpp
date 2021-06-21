// O(sqrt(N)) Trial factorization
vector<long long> factor(long long n){
	vector<long long> factors;
	if(n == 1){
		return factors;
	}
	long long i = 2;
	while(i*i <= n){
		while(n%i == 0){
			factors.push_back(i);
			n /= i;
		}
		i++;
	}
	if(n>1) factors.push_back(n);
	return factors;
}