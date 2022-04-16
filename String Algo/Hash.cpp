struct Hash {
    int P = 101;
    int MOD = 998244353;
    vector<int> p, h;
    int n;
    Hash(string& s) {
        n = s.size();
        p.resize(n + 1, 1);
        h.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = ((long long)p[i - 1] * P) % MOD;
        }
        for (int i = 0; i < n; ++i) {
            h[i + 1] = ((long long)p[n - i - 1] * (s[i] - 'a' + 1) + h[i]) % MOD;
        }
    }
    int get(int L, int R) {
        return ((long long)p[L - 1] * (h[R] - h[L - 1] + MOD)) % MOD;
    }
};
// 1-indexed Hash
