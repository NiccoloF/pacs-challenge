
#include <iostream>
#include <cmath>

#include "Solver.hpp"
#include "Getpot"
#include "readparameters.hpp"
#include "muParser_fun.hpp"

double f(double time,double y);
double df(double time,double y);

int main(int argc,char** argv) {

    GetPot c1(argc,argv);

    bool verbose = c1.search(1,"-v");
    std::string filename = c1.follow("parameters.pot","-p");

    std::cout<<"reading file from "<<filename<<std::endl;

    parameters param = readParam(filename,verbose);

    const auto& [f,df,time,N,u0] = param;

    std::cout << f <<std::endl;
    std::cout << df <<std::endl;

    muParser_fun f_(f);
    muParser_fun df_(df);


    //const std::function<double(double,double)> f_ = f;
    //const std::function<double(double,double)> df_ = df;

    Solver solver(f_,df_,u0,time,N);

    auto result = solver.crankNicolson();

    std::cout << "Result file: result.dat" << std::endl;
    std::ofstream of("result.dat");
    of << "#TIME\tU_H"<<"\n";

    for(size_t i = 0;i<result[0].size();++i)
    {
      of.setf(std::ios::left, std::ios::adjustfield);
      of.width(16);
      of<<result[0][i]<<"\t\t"<< result[1][i]<<"\n";
    }

    of.close();
    return 0;
    /*
    for(int i = 0;i<result[0].size();++i)
    {
      std::cout << result[0][i]<<"   "<<result[1][i]<<std::endl;
    }
    return 0;
    */
}

double f(double time,double y)
{
  return -1 * time *exp(-1 * y);
}
double df(double time,double y)
{
  return time *exp(-1 * y);
}
