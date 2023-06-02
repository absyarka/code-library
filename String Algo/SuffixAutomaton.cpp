const int ALPHABET = 26;

struct SuffixAutomaton {
    SuffixAutomaton(const string& t) {
        rootInit();
        for (int i = 0; i < t.size(); ++i) {
            addLetter(t[i] - 'a');
        }
    }

    SuffixAutomaton() {
        rootInit();
    }

    void init() {
        suffLink.emplace_back(-1);
        maxParent.emplace_back(-1);
        go.emplace_back(vector<int>(ALPHABET, -1));
    }

    void rootInit() {
        last = 0;
        freePos = 1;
        init();
    }

    void addLetter(int x) {
        int A = last;
        int B = freePos++;
        last = B;
        init();
        maxParent[B] = A;
        while (A != -1 && go[A][x] == -1) {
            go[A][x] = B;
            A = suffLink[A];
        }
        if (A == -1) {
            suffLink[B] = 0;
            return;
        }
        int C = go[A][x];
        if (C == B) {
            suffLink[B] = 0;
        } else if (maxParent[C] == A) {
            suffLink[B] = C;
        } else {
            int E = freePos++;
            init();
            maxParent[E] = A;
            go[E] = go[C];
            suffLink[E] = suffLink[C];
            suffLink[C] = E;
            suffLink[B] = E;
            while (A != -1 && go[A][x] == C) {
                go[A][x] = E;
                A = suffLink[A];
            }
        }
    }

    int freePos;
    int last;
    vector<int> suffLink;
    vector<int> maxParent;
    vector<vector<int> > go;
};
