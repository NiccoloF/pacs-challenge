#include "parameters.hpp"

std::ostream& operator<<(std::ostream& out,const parameters& par)
{
  out <<"f(t,y)="<<par.f<<"\ndf(t,y)="<<par.df<<"\nuex(t,y)="<<par.uex<<"\nINPUT PARAMETERS:\n"<<"{\n TIME: "<<par.time
      <<"\n N: "<<par.N<<"\n Y_0: "<<par.y_0<<"\n THETA: "<<par.theta<<"\n}"<<std::endl;
  return out;
}
