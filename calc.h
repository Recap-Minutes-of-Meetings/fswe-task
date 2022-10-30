#include "list.cpp"
#include "exception.cpp"

int prior(int c);
int count(int a, int op, int b);
int is_aryphmetic(char a);
void rec_delete(struct List *l);
int calc(const char *s, struct List *prev = nullptr);
int last_calc(struct List *prev, int cur_num);