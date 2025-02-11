constexpr int N 300000;
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)

int seg[4 * N + 1];
int a[N + 1]; // (input) an array of data to operate querys and updates over

// O(1)
int merge(int nl, int nr) {
    return nl + nr; // (input) this operation must be reversable and conform to problem
}

// O(N)
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

// O(log(N))
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

// O(log(N))
void update(int cur, int l, int r, int i, int x) {
    int m = (l + r) / 2;

    if (r < i or l > i) { // this cur is out of my desired range of search [i,j]
        return;
    }

    if (l >= i and r <= i) { // this cur is completely inside my desired range of search [i,j]
        seg[cur] = x;
        return;
    }

    update(LEFT(cur), l, m, i, x);
    update(RIGHT(cur), m + 1, r, i, x);

    seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}