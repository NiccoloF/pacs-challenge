#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <iostream>

struct parameters
{
  std::string f = "0";
  std::string df = "0";
  std::string uex = "0";
  double time = 10;
  double N = 1e3;
  double y_0 = 0;
  double theta = 1/2;
};

std::ostream& operator<<(std::ostream& out,const parameters&);

#endif //PARAMETERS_HPP
