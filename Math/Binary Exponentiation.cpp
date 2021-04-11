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