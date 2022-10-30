#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>

struct Exception
{
  const char *message;
  Exception(const char *message) : message(message) {}
};

struct List
{
  int op;
  int num;
  int prior;
  struct List *prev;
  List(int op = '+', int num = 0, int prior = 0, struct List *prev = nullptr) : op(op), num(num), prior(prior), prev(prev) {}
};

class Calculator
{
public:
  int calc(const char *s, struct List *prev);

private:
  int prior(int c);
  int count(int a, int op, int b);
  int is_aryphmetic(char a);
  void rec_delete(struct List *l);
  int calc(const char *s, struct List *prev = nullptr);
  int last_calc(struct List *prev, int cur_num);
};

#endif
