#include <iostream>
#include <cmath>

#include "Solver.h"


double f(double time,double y);
double df(double time,double y);

int main() {
    const std::function<double(double,double)> f_ = f;
    const std::function<double(double,double)> df_ = df;
    Solver solver(f_,df_);
    auto result = solver.crankNicolson();
    for(int i = 0;i<result[0].size();++i)
    {
      std::cout << result[0][i]<<"   "<<result[1][i]<<std::endl;
    }
    return 0;
}

double f(double time,double y)
{
  return -1 * time *exp(-1 * y);
}
double df(double time,double y)
{
  return time *exp(-1 * y);
}
