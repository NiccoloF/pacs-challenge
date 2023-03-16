#include "muParser_fun.hpp"

muParser_fun::muParser_fun(const std::string& fun)
{
  try
  {
    muParser.DefineVar("t",&(this->mt_value));
    muParser.DefineVar("y",&(this->my_value));
    muParser.SetExpr(fun);
  }
  catch(mu::Parser::exception_type& e)
  {
    using std::cout;
 cout << "Content of muParser exception"
      << "\n";
 cout << "Message:  " << e.GetMsg() << "\n";
 cout << "Formula:  " << e.GetExpr() << "\n";
 cout << "Token:    " << e.GetToken() << "\n";
 cout << "Position: " << e.GetPos() << "\n";
 cout << "Errc:     " << e.GetCode() << "\n";
  }
}

double muParser_fun::operator()(const double t_value,const double y_value)
{
  double x = 0.;
  mt_value = t_value;
  my_value = y_value;

  try
  {
    // double a = t_value;
    // double b = y_value;

     //muParser.DefineVar("t",&(this->mt_value));
     //muParser.DefineVar("y",&(this->my_value));
     //std::cout<<"mtvalue = "<<mt_value<<std::endl;
     //std::cout<<"x = "<<muParser.Eval()<<std::endl;
     x = muParser.Eval();
     /*
     std::cout<<"t = "<<t_value<<std::endl;
     std::cout<<"y = "<<y_value<<std::endl;
     std::cout<<"x = "<<x<<std::endl;
     */
  }
  catch(mu::Parser::exception_type& e)
  {
    using std::cout;
 cout << "Content of muParser exception"
      << "\n";
 cout << "Message:  " << e.GetMsg() << "\n";
 cout << "Formula:  " << e.GetExpr() << "\n";
 cout << "Token:    " << e.GetToken() << "\n";
 cout << "Position: " << e.GetPos() << "\n";
 cout << "Errc:     " << e.GetCode() << "\n";
  }
  return x;
}
