#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__


#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>   

struct Exception
{
  const char *message;
  Exception(const char *message) : message(message) {
    std::ofstream out("ErrorLog.txt", std::ios::out | std::ios::app);
    std::time_t m = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    out << std::ctime(&m) << "\t\t" << message <<'\n';
    out.close();
  }
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
  int calc(const char *s, struct List *prev = nullptr);

private:
  int prior(int c);
  int count(int a, int op, int b);
  int is_aryphmetic(char a);
  void rec_delete(struct List *l);
  //int calc(const char *s, struct List *prev = nullptr);
  int last_calc(struct List *prev, int cur_num);
};

#endif
