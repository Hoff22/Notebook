#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

constexpr int N 200000;

struct Line{
	int a, int b;
};

int eval(Line l, int x){
	return l.a * x + l.b;
}

Line lichao[4*N+1];

void add_line(Line nl, int cur = 1, int l = 1, int r = N){
	int m = l + (r-l)/2;

	if(eval(nl, m) > eval(lichao[cur], m)) swap(nl, lichao[cur]);

	if(l == r) return;

	if(eval(nl, l) > eval(lichao[cur], l)){
		add_line(nl, LEFT(cur), l, m);
	}
	if(eval(nl, r) > eval(lichao[cur], r)){
		add_line(nl, RIGHT(cur), m+1, r);
	}
}

void insert(Line nl, int i = 1, int j = N, int cur = 1, int l = 1, int r = N){
	int m = l + (r-l)/2;

	if(l >= i and j <= r){
		add_line(nl, cur, l, r);
		return;
	}

	if(j < l or r < i) return;

	insert(nl, LEFT(x), i, j, l, m);
	insert(nl, RIGHT(x), i, j, m+1, r);
}

int query(int x, int cur = 1, int l = 1, int r = N){
	int m = l + (r-l)/2;

	if(l == r) return eval(lichao[cur], x);

	if(x <= m) return max(eval(lichao[cur], x), query(x, LEFT(cur), l, m));
	if(x >  m) return max(eval(lichao[cur], x), query(x, RIGHT(cur), m+1, r));
	return eval(lichao[cur], x);
}