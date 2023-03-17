
// plot "result.dat" w p lw 2 title 'uh' , log(1-x**2/2)  lw 2 title 'u_ex'

#include <iostream>
#include <cmath>

#include "Solver.hpp"
#include "Getpot"
#include "readparameters.hpp"
#include "muParser_fun.hpp"

int main(int argc,char** argv) {
    
    GetPot c1(argc,argv);
    /*
      -v : show a list of parameters 
      -p : specify the file name 
    */
    bool verbose = c1.search(1,"-v");
    std::string filename = c1.follow("parameters.pot","-p");

    std::cout<<"reading file from "<<filename<<std::endl;

    // read parameter from filename and store the result in the parameters class 
    parameters param = readParam(filename,verbose);
   
    const auto& [f,df,time,N,u0,theta] = param;

    // initialize a muparser object 
    muParser_fun f_(f);
    muParser_fun df_(df);

    Solver solver(f_,df_,u0,time,N,theta);
    auto result = solver.theta_method();

    // write the result in ../result.dat 
    std::cout << "Result file: result.dat" << std::endl;
    std::ofstream of("../result.dat");
    of << "#TIME\t\tU_H"<<"\n";

    for(size_t i = 0;i<result[0].size();++i)
    {
      of.setf(std::ios::left, std::ios::adjustfield);
      of.width(16);
      of<<result[0][i]<<"\t\t"<< result[1][i]<<"\n";
    }

    of.close();
    return 0;
}

