// O(N^2)
int lcs(vector<int>& a, vector<int>& b){
	int n = a.size();
	int m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!i or !j){
				dp[i][j] = (a[i] == b[j]);
				continue;
			}
			dp[i][j] = max({
				dp[i-1][j-1] + (a[i] == b[j]),
				dp[i-1][j],
				dp[i][j-1]
			});
		}
	}

	return dp[n-1][m-1];
}