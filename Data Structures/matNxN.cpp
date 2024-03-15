template <typename T, int DIM, int mod = 1000000007>
struct mat{
    T v[DIM][DIM];
 
    mat(){
        memset(v, 0, sizeof(v));
        for(int i = 0; i < DIM; i++){
            v[i][i] = 1;
        }
    }
 
    mat(vector<vector<T>>& val){
        assert(val.size() == DIM);
        for(int i = 0; i < DIM; i++){
            assert(val[i].size() == DIM);
            for(int j = 0; j < DIM; j++){
                v[i][j] = val[i][j];
            }
        }
    }
 
    const T* operator[](const int idx) const{
        return v[idx];
    }
 
    T* operator[](const int idx){
        return v[idx];
    }
 
    mat<T,DIM,mod>& operator+=(const mat<T,DIM,mod>& a){
        for(int r = 0; r < DIM; r++){
            for(int c = 0; c < DIM; c++){
                v[r][c] = (v[r][c] + (a[r][c] % mod)) % mod;
            }
        }
        return *this;
    }
 
    mat<T,DIM,mod>& operator*=(const mat<T,DIM,mod>& a){
        vector<vector<T>> res_(DIM, vector<T>(DIM, 0));
        mat<T,DIM,mod> res(res_);
        for(int r = 0; r < DIM; r++){
            for(int c = 0; c < DIM; c++){
                for(int i = 0; i < DIM; i++){
                    T nv = ((v[r][i] % mod) * (a[i][c] % mod)) % mod;
                    res[r][c] = ((res[r][c] % mod) + nv) % mod;
                }
            }
        }
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                v[i][j] = (res[i][j] % mod);
            }
        }
        return *this;
    }
 
    friend mat<T,DIM,mod> operator*(mat<T,DIM,mod> a, const mat<T,DIM,mod> b){
        a *= b;
        return a;
    }
 
    friend ostream& operator<<(ostream& os, mat<T,DIM,mod> a){
        for(int i = 0; i < DIM; i++){
            for(int j = 0; j < DIM; j++){
                os << a[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }
 
};
 
typedef mat<long long, 6, MOD> llm;