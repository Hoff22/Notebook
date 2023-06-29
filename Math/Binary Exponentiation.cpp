// O(log_2(N))
long long pow_(long long a, long long b, int mod){
    long long res = 1;
    while(b){
    	if(b&1){
    		res *= a;
            res %= mod;
    	}
    	a *= a;
        a %= mod;
    	b >>= 1;
    }
    return res; 
}