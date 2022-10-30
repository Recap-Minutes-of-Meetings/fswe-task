struct List {
    int op;
    int num;
    int prior;
    struct List *prev;
    List(int op = '+', int num = 0, int prior = 0, struct List *prev = nullptr) : op(op), num(num), prior(prior), prev(prev) {}
};

