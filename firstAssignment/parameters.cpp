#include "parameters.hpp"

std::ostream& operator<<(std::ostream& out,const parameters& par)
{
  out << "INPUT PARAMETERS"<<std::endl<<"{\n TIME: "<<par.time
      <<" N: "<<par.N<<" Y_0: "<<par.y_0<<"\n}"<<std::endl;
  return out;
}
