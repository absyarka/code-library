struct SegTree {
    vector<int> t;
    int n;
    SegTree(vector<int>& a) {
        n = a.size();
        t.resize(2 * n);
        for (int i = 0; i < n; ++i) {
            t[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    void upd(int pos, int x) {
        pos = (pos + n - 1);
        t[pos] = x;
        for (int i = pos / 2; i > 0; --i) {
            t[i] = min(t[2 * i], t[2 * i + 1]);
        }
    }
    int get(int L, int R) {
        L += n;
        R += n;
        int res = INF;
        for (; L < R; L /= 2, R /= 2) {
            if (L & 1) res = min(res, t[L++]);
            if (R & 1) res = min(res, t[--R]);
        }
        return res;
    }
};
// Segment Tree from below for MIN
