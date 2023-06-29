
/*
	segmented_tree(int n, T identity_element, vector<T>& input, T (*m)(T,T))

	n = size of input
	identity_element = identity for merge query outside of range
	input = data vector 1 indexed
	m = merge function pointer 

	seg.update(i, x) = point update with X
	seg[{i,j}] = range query i, j
	

*/

template <class T>
class segmented_tree{
public:
	int s;
	T (*merge)(T,T);
	T ie;
	vector<T> seg;


	void build(int cur, int l, int r, vector<T>& input) {
		int m = (l + r) / 2;

		if (l == r) {
			seg[cur] = input[l];
			return;
		}

		build(LEFT(cur), l, m, input);
		build(RIGHT(cur), m + 1, r, input);

		seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	segmented_tree(int n, T identity_element, vector<T>& input, T (*m)(T,T)){
		s = n;
		merge = m;
		ie = identity_element;
		seg.resize(s*4+1);
		build(1,1,n,input);
	}

	T query_(int cur, int l, int r, int i, int j) {
		T nl, nr; 
		int m = (l + r) / 2;

		if (r < i or l > j) { // this cur is out of my desired range of search [i,j]
			return ie;
		}

		if (l >= i and r <= j) { // this cur is completely inside my desired range of search [i,j]
			return seg[cur];
		}

		nl = query_(LEFT(cur), l, m, i, j);
		nr = query_(RIGHT(cur), m + 1, r, i, j);

		return merge(nl, nr); // return the merge of all curs that are inside my desired range of search [i,j]
	}

	T query(int i, int j){
		return query_(1,1,s,i,j);
	}

	void update(int i, T x){
		update_(1,1,s,i,x);
	}

	void update_(int cur, int l, int r, int i, T x) {
		int m = (l + r) / 2;

		if (r < i or l > i) {
			return;
		}

		if (l == r) {
			seg[cur] = x;
			return;
		}

		update_(LEFT(cur), l, m, i, x);
		update_(RIGHT(cur), m + 1, r, i, x);

		seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
	}

	T operator[](const pair<int,int> i){
		return query_(1,1,s,i.fi,i.se);
	}

};
