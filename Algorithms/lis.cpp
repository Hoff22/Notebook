int constexpr INF = 0x3f3f3f3f;

// O(N*log(N))
// returns the size of the lis
int lis(vector<int>& a){
    int n = a.size();
    vector<int> d(n+1, INF);
    d[0] = -INF;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = (int)(lower_bound(d.begin(), d.end(), a[i]) - d.begin());
        if(j > n) continue;
        d[j] = min(a[i], d[j]);
        ans = max(ans, j);
    }

    return ans;
}

// O(N*log(N))
// returns the lis
vector<int> lis_vec(vector<int>& a){
    int n = a.size();
    vector<int> d(n+1, -1);
    vector<int> p(n+1, -1);
    d[0] = -2;

    auto comp = [&](int j, int val){
        if(j == -1) return false;    // sub for  INF
        if(j == -2) return true;     // sub for -INF
        return a[j] < val;
    };

    int ans = 0;
    for(int i = 0; i < n; i++){
        int j = (int)(lower_bound(d.begin(), d.end(), a[i], comp) - d.begin());
        if(j>n) continue;

        if(d[j] == -1){
            p[i] = d[j-1];
            d[j] = i;
        }
        else if(a[d[j]] > a[i]){
            p[i] = p[d[j]];
            d[j] = i;
        }

        ans = max(ans, j);
    }

    vector<int> v;
    int cur = d[ans];
    while(cur != -2){
        v.push_back(a[cur]);
        cur = p[cur];
    }

    reverse(v.begin(), v.end());

    return v;
}