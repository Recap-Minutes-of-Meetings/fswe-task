#include <iostream>
#include <climits>
#include <cctype>
#include "calc.h"

using namespace std;

int prior(int c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

int count(int a, int op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw Exception("Error: division by zero");
            }
            return a / b;
        default:
            return 0;
    }
}

int is_aryphmetic(char a) {
    return (a == '+' || a == '-' || a == '*' || a == '/');
}

void rec_delete(struct List *l) {
    if (l != nullptr) {
        rec_delete(l->prev);
        delete l;
    }
}

enum Expect {
    NUM,
    OPERATOR,
    READING_NUM
};

int last_calc(struct List *prev, int cur_num) {
    int res;
    if (prev->prior == 0) {
        rec_delete(prev);
        return cur_num;
    } else if (prev->prior > prev->prev->prior) {
        try {
            prev->num = count(prev->num, prev->op, cur_num);
        } catch (struct Exception &e) {
            rec_delete(prev);
            throw;
        }
        if (prev->prev->prior != 0) {
            try {
                res = count(prev->prev->num, prev->prev->op, prev->num);
            } catch (struct Exception &e) {
                rec_delete(prev);
                throw;
            }
        } else {
            res = prev->num;
        }
        rec_delete(prev);
        return res;
    } else if (prev->prev->prior != 0) {
        try {
            prev->num = count(prev->prev->num, prev->prev->op, prev->num);
            res = count(prev->num, prev->op, cur_num);
        } catch (struct Exception &e) {
            rec_delete(prev);
            throw;
        }
        rec_delete(prev);
        return res;
    }
    rec_delete(prev);
    return 0;
}


int calc(const char *s, struct List *prev) {

    if (prev == nullptr) {
        prev = new List;
    }

    Expect is_expecting = NUM;
    long cur_num = 0;
    int cur_op;
    bool was_minus = false;
    while (1) {
        if (is_expecting == NUM) {
            if (*s == '-') {
                was_minus = !was_minus;
            } else if (isdigit(*s)) {
                cur_num = *s - '0';
                is_expecting = READING_NUM;
            } else if (isspace(*s)) {
                s++;
                continue;
            } else {
                rec_delete(prev);
                throw Exception("Error: Can't interpret input into expression");
            }
        } else if (is_expecting == READING_NUM) {
            if (isdigit(*s)) {
                cur_num *= 10;
                cur_num += *s - '0';
                if ((!was_minus && cur_num > INT_MAX) || (was_minus && cur_num > INT_MAX + 1l)) {
                    rec_delete(prev);
                    throw Exception("Error: The number is too big to be of type int");
                }
            } else if (isspace(*s)) {
                is_expecting = OPERATOR;
                if (was_minus) {
                    cur_num = -cur_num;
                }
            } else if (is_aryphmetic(*s)) {
                if (was_minus) {
                    cur_num = -cur_num;
                }
                cur_op = *s;
                s++;
                break;
            } else if (*s == '\0') {
                if (was_minus) {
                    cur_num = -cur_num;
                }
                return last_calc(prev, cur_num);
            } else {
                rec_delete(prev);
                throw Exception("Error: Can't interpret input into expression");
            }
        } else if (is_expecting == OPERATOR){
            if (is_aryphmetic(*s)) {
                cur_op = *s;
                s++;
                break;
            } else if (isspace(*s)) {
                s++;
                continue;
            } else if (*s == '\0') {
                if (was_minus) {
                    cur_num = -cur_num;
                }
                return last_calc(prev, cur_num);
            } else {
                rec_delete(prev);
                throw Exception("Error: Can't interpret input into expression");
            }
        }
        s++;
    }

    auto l = new List(cur_op, cur_num, prior(cur_op), prev);
    if (l->prev->prior < l->prior) {
        return calc(s, l);
    } else {
        while (l->prev->prior >= l->prior) {
            try {
                l->num = count(l->prev->num, l->prev->op, l->num);
            } catch (struct Exception &e){
                rec_delete(prev);
                throw;
            }
            struct List *to_del = l->prev;
            l->prev = l->prev->prev;
            delete to_del;
        }
        return calc(s, l);
    }
}


