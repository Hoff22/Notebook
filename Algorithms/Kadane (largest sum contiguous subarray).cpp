#define N 200000
#define INF 0x3f3f3f3f

int dp[N+1];
int a[N+1]; // (input) Int vector
int n; 		// (intput) Size of input vector

/* O(N) */
int lcs(){

	// Initialize dp.
	dp[0] = a[0];

	// Calculate max sum ending in a[i].
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i-1] + a[i], a[i]);
	}

	// Return max-sum sub-array.
	return *max_element(dp, dp + n);
}