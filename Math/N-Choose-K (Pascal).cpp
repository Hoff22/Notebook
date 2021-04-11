// Combinacao (A,B) == (B,A)
// C = n! / p!(n-p)!

int choose(int n, int p)
{
   if (n < p)
   {
      return 0;
   }
   else if (p == 0)
   {
      return 1;
   }
   else
   {
      return choose(n - 1, p) + choose(n - 1, p - 1);
   }
}

//////////////////////////////////////////////////////////

#define MOD (1e9+7)
#define N 1000000

long long factsMOD[N+1];

void factInit(){
	facts[0] = 1;
	for(int i = 1; i <= N; i++){
		facts[i] = facts[i-1] * i * 1ll % MOD;
	}
}

long long quick_power(int a, int b){
   long long ans = 1;

   while(b){
      if(b & 1){
         ans = 1ll * ans * a % MOD;
      }
      
      a = 1ll * a * a % MOD;
      
      b >>= 1;
   }

   return ans;
}

long long choose(int n, int k){
   return factsMOD[n] * quick_power(factsMOD[n], MOD - 2) % MOD * quick_power(factsMOD[n - k], MOD - 2) % MOD;
}

///////////////////////////////////////////////////////////////////////////////////
// N = max number n to compute n choose k;
// n choose k = choose[n][k]; 
long long choose[N][N];

void pascal(){
   for(int i = 0; i <= N; i++){
      choose[i][0] = 1;
   }
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= i; j++){
         choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
      }
   }
}

