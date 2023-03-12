#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>

struct parameters
{
  double time = 10;
  double N = 1e3;
  double y_0 = 0;
};

std::ostream& operator<<(std::ostream& out,const parameters&);

#endif //PARAMETERS_HPP
