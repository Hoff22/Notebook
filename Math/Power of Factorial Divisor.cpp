// Finding the largest power x of k that divides n!

int fact_pow(int n, int k){
   int ans = 0;
   while(n){
      n /= k;
      ans += n;
   }
   return ans
}
