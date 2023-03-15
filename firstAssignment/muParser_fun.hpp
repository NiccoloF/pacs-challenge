#ifndef MUPARSER_FUN_HPP
#define MUPARSER_FUN_HPP
#include "muParser.h"

class muParser_fun
{
public:

  muParser_fun(const std::string& fun);
  double operator()(const double t_value,const double y_value);

private:
  double my_value ;
  double mt_value ;
  mu::Parser muParser;
};

#endif //MUPARSER_FUN_HPP
