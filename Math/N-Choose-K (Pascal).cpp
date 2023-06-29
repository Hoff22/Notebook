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

long long f[N + 1];

/* O(Log(min(a, b))) - Extended Euclidean Algorithm.
   Returns a solution to a * x + b * y = gcd(a, b).
   Returns |x| <= |a / gcd(a, b)|, |y| <= |b / gcd(a, b)| and gcd(a, b). */
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {
    long long x, y, gcd;

    if (a == 0) {
        return {b, 0, 1};
    }

    tie(gcd, x, y) = extended_gcd(b % a, a);

    return {gcd, y - (b / a) * x, x};
}

/* O(Log(M)) - Returns the modular multiplicative inverse of a mod m, if it exists.
Returns x that satisfies a * x = 1 (mod m) if a and m are coprime. Returns 0 otherwise. */
long long modular_inverse(long long a, long long m) {
    long long gcd, x, y;

    tie(gcd, x, y) = extended_gcd((a % m + m) % m, m);

    if (gcd != 1) {
        return 0;
    }

    return (x % m + m) % m;
}

/* O(Log(M)) - This only works if k! * (n - k)! is coprime with m. */
long long nck(long long n, long long k, long long m) {
    long long num, den;

    // Trivial case.
    if (k < 0 or k > n) {
        return 0;
    }

    num = f[n];
    den = (f[k] * f[n - k]) % m;

    return (num * modular_inverse(den, m)) % m;
}

/* O(N). */
void nck_init(long long m) {
    f[0] = 1;

    for (long long i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * i) % m;
    }
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

