#define MOD 10000007

// O(log_2(N))
long long pow_(long long a, long long b){
    long long res = 1;
    while(b){
    	if(b&1){
    		res *= a;
    	}
    	a *= a;
    	b >>= 1;
    }
    return res; 
}

// O(log_2(N))
// Given Euler's Theorem that states:
// b^-1 % MOD == b^MOD-2
// returns (a / b) % MOD
long long divideM(long long a, long long b){
	return ((a % MOD) * pow_(b, MOD-2)) % MOD;
}