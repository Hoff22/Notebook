#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int seg[4 * N + 1];
int a[N + 1]; // (input) an array of data to operate querys and updates over

int merge(int nl, int nr) {
	return nl + nr; // (input) this operation must be reversable and conform to problem
}

void build(int cur, int l, int r) {
	int m = (l + r) / 2;

	if (l == r) {
		seg[cur] = a[l];
		return;
	}

	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

int query(int cur, int l, int r, int i, int j) {
	int nl, nr, m = (l + r) / 2;

	if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
		return 0;
	}

	if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
		return seg[cur];
	}

	nl = query(LEFT(cur), l, m, i, j);
	nr = query(RIGHT(cur), m + 1, r, i, j);

	return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
}

void update(int cur, int l, int r, int i, int x) {
	int m = (l + r) / 2;

	if (r < i or l > i) {
		return;
	}

	if (l == r) {
		seg[cur] = x;
		return;
	}

	update(LEFT(cur), l, m, i, x);
	update(RIGHT(cur), m + 1, r, i, x);

	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

// usage example:
int main() {
	int n, m, l, r, op, x, i;

	scanf("%d%d", &n, &m);

	// O(N)
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}

	// O(N)
	build(1, 1, n);

	// O(M * Log(N))
	while (m--) {
		scanf("%d", &op);

		if (op == 1) { // UPDATE
			scanf("%d%d", &i, &x);
			update(1, 1, n, i, x);
		}
		else if (op == 2) { // QUERY
			scanf("%d%d", &l, &r);
			print("%d", query(1, 1, n, l, r));
		}
	}

	return 0;
}